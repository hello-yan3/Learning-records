/**
 * @brief 图 (Graph)
 * @attention：
 * 
 * 图的基本概念
 * 1. 图：由顶点集合和边集合组成的非线性数据结构，表示对象之间的多对多关系
 * 2. 特点：
 *    - 允许存在多个连通路径
 *    - 可以表示复杂的网状结构
 *    - 边可以是有方向的或无方向的
 *    - 支持权重属性（带权图）
 * 
 * 基础术语：
 * - 顶点(Vertex)：图中的基本单元
 * - 边(Edge)：连接两个顶点的关系
 * - 度(Degree)：某个顶点的边数
 * - 邻接点：通过边直接相连的顶点
 * - 路径：顶点序列构成的边序列
 * 
 * 图的分类：
 * | 类型         | 特点                     |
 * |--------------|--------------------------|
 * | 无向图       | 边无方向                |
 * | 有向图       | 边有方向（弧）          |
 * | 完全图       | 任意两顶点都有边相连    |
 * | 稀疏/稠密图  | 边数远少于/接近完全图    |
 * | 带权图       | 边具有权重值            |
 * 
 * 存储结构：
 * 1. 邻接矩阵：
 *    - 使用二维数组存储边关系
 *    - 适合稠密图，空间复杂度O(n²)
 *    - 判断边存在：O(1)
 * 
 * 2. 邻接表：
 *    - 数组+链表组合结构
 *    - 适合稀疏图，空间复杂度O(n+e)
 *    - 遍历邻接点：O(度数)
 * 
 * 基本操作：
 * - 深度优先遍历(DFS)：递归/栈实现，时间复杂度O(n+e)
 * - 广度优先遍历(BFS)：队列实现，时间复杂度O(n+e)
 * - 最小生成树：Prim/Kruskal算法
 * - 最短路径：Dijkstra/Bellman-Ford/Floyd算法
 * 
 * 应用场景：
 * - 社交网络分析
 * - 地铁线路规划
 * - 任务调度依赖
 * - 网页链接分析
 */
/***********************静态实现***********************/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define MaxVertexNum 10 // 顶点数目最大值

// ==================== 数据结构定义 ====================
/**
 * @brief 边/弧结构体
 */
typedef struct ArcNode
{
    int adjvex;           ///< 边/弧指向的目标顶点索引
    struct ArcNode *next; ///< 指向下一条弧的指针
    int info;             ///< 边权值
} ArcNode;

/**
 * @brief 顶点结构体
 */
typedef struct VNode
{
    char data;      ///< 顶点信息
    ArcNode *first; ///< 指向第一条边/弧的指针
} VNode, AdjList[MaxVertexNum];

/**
 * @brief 邻接表存储的图结构体
 */
typedef struct
{
    AdjList vertices;   ///< 顶点数组
    int vexnum, arcnum; ///< 当前顶点数和边数/弧数
} ALGraph;

// ==================== 函数声明 ====================
int GetVertexIndex(ALGraph G, char x);
int InsertVertex(ALGraph *G, char x);
int AddEdge(ALGraph *G, char x, char y, int weight);
int FirstNeighbor(ALGraph G, int x);
int NextNeighbor(ALGraph G, int x, int y);
void CreateGraph(ALGraph *G);
void BFS(ALGraph G, int v, bool visited[]);
void BFSTraverse(ALGraph G);
void DFS(ALGraph G, int v, bool visited[]);
void DFSTraverse(ALGraph G);
void Dijkstra(ALGraph G, int start);
void Floyd(ALGraph G);

////////////////////////////////////////////////////////
// ==================== 函数实现 ====================
////////////////////////////////////////////////////////

/**
 * @brief 查找顶点在顶点表中的索引
 *
 * @param G 图结构体
 * @param x 要查找的顶点字符
 * @return int 返回顶点索引，不存在返回-1
 */
int GetVertexIndex(ALGraph G, char x)
{
    for (int i = 0; i < G.vexnum; i++)
    {
        if (G.vertices[i].data == x)
        {
            return i; // 找到顶点返回索引
        }
    }
    return -1; // 未找到返回-1
}

/**
 * @brief 插入顶点x到图G中
 *
 * @param G 图结构体指针
 * @param x 要插入的顶点字符
 * @return int 成功插入返回1，顶点已存在或图满返回0
 */
int InsertVertex(ALGraph *G, char x)
{
    int index = GetVertexIndex(*G, x);
    if (index != -1)
        return 0; // 顶点已存在
    if (G->vexnum >= MaxVertexNum)
        return 0; // 顶点数超过上限

    G->vertices[G->vexnum].data = x;
    G->vertices[G->vexnum].first = NULL;
    G->vexnum++; // 顶点数增加
    return 1;
}

/**
 * @brief 添加有向边<x,y>到图G中
 *
 * @param G 图结构体指针
 * @param x 边的起点字符
 * @param y 边的终点字符
 * @param weight 边的权值
 * @return int 成功添加返回1，顶点不存在或边已存在返回0
 */
int AddEdge(ALGraph *G, char x, char y, int weight)
{
    int i = GetVertexIndex(*G, x);
    int j = GetVertexIndex(*G, y);
    if (i == -1 || j == -1)
        return 0; // 顶点不存在

    // 创建新的边节点
    ArcNode *node = (ArcNode *)malloc(sizeof(ArcNode));
    if (!node)
        return 0; // 内存分配失败

    node->adjvex = j;
    node->info = weight;
    node->next = G->vertices[i].first;
    G->vertices[i].first = node;
    G->arcnum++; // 边数增加
    return 1;
}

/**
 * @brief 获取顶点x的第一个邻接点
 *
 * @param G 图结构体
 * @param x 顶点索引
 * @return int 返回第一个邻接点索引，无邻接点返回-1
 */
int FirstNeighbor(ALGraph G, int x)
{
    if (x < 0 || x >= G.vexnum)
        return -1; // 顶点无效
    if (G.vertices[x].first == NULL)
        return -1;                      // 无邻接点
    return G.vertices[x].first->adjvex; // 返回第一个邻接点索引
}

/**
 * @brief 获取顶点x相对于y的下一个邻接点
 *
 * @param G 图结构体
 * @param x 当前顶点索引
 * @param y 当前邻接点索引
 * @return int 返回下一个邻接点索引，无更多邻接点返回-1
 */
int NextNeighbor(ALGraph G, int x, int y)
{
    if (x < 0 || x >= G.vexnum)
        return -1; // 顶点无效

    ArcNode *p = G.vertices[x].first;
    // 查找当前邻接点y对应的节点
    while (p != NULL && p->adjvex != y)
    {
        p = p->next;
    }

    if (p == NULL || p->next == NULL)
        return -1;          // 未找到或无后续节点
    return p->next->adjvex; // 返回下一个邻接点索引
}

/**
 * @brief 获取顶点u到v的边的权重
 *
 * @param G 图结构体
 * @param u 起始顶点索引
 * @param v 目标顶点索引
 * @return int 边的权重，若不存在返回INT_MAX
 */
int GetWeight(ALGraph G, int u, int v)
{
    ArcNode *p = G.vertices[u].first;
    // 遍历邻接链表查找目标顶点
    while (p != NULL)
    {
        if (p->adjvex == v)
        {
            return p->info; // 找到边返回权重
        }
        p = p->next;
    }
    return INT_MAX; // 未找到返回无穷大
}

/**
 * @brief 创建图的初始结构
 *
 * @param G 图结构体指针
 */
void CreateGraph(ALGraph *G)
{
    // 初始化顶点表
    char vertices[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    G->vexnum = 7;
    G->arcnum = 0;

    // 初始化顶点信息和邻接链表
    for (int i = 0; i < G->vexnum; i++)
    {
        G->vertices[i].data = vertices[i];
        G->vertices[i].first = NULL;
    }

    // 添加预定义的边和权值
    char edges[][2] = {
        {'A', 'G'}, {'A', 'F'}, {'A', 'C'}, {'A', 'B'}, {'B', 'E'}, {'B', 'A'}, {'C', 'F'}, {'C', 'D'}, {'C', 'B'}, {'C', 'A'}, {'D', 'E'}, {'D', 'B'}, {'F', 'E'}, {'F', 'A'}, {'F', 'G'}, {'G', 'D'}};
    int weights[] = {1, 4, 3, 1, 5, 6, 5, 3, 4, 4, 2, 3, 2, 6, 2, 1};

    int num_edges = sizeof(edges) / sizeof(edges[0]);
    // 批量添加边
    for (int k = 0; k < num_edges; k++)
    {
        AddEdge(G, edges[k][0], edges[k][1], weights[k]);
    }
}

/**
 * @brief 广度优先搜索核心函数
 *
 * @param G 图结构体
 * @param v 起始顶点索引
 * @param visited 访问标记数组
 */
void BFS(ALGraph G, int v, bool visited[])
{
    // 队列结构定义
    typedef struct
    {
        int data[MaxVertexNum];
        int front, rear;
    } Queue;

    // 队列操作函数（内联实现）
    #define EnQueue(Q, x)       do { Q.data[Q.rear++] = x;  } while(0)   
    #define DeQueue(Q, x)       do { x = Q.data[Q.front++]; } while(0)   
    #define QueueEmpty(Q)       (Q.front == Q.rear)

    Queue Q; // 创建队列
    Q.front = Q.rear = 0;

    //////////////////////////////

    printf("%c ", G.vertices[v].data); // 访问顶点
    visited[v] = true;
    EnQueue(Q, v); // 起始顶点入队
 
    // 队列不空时循环
    while (!QueueEmpty(Q))
    {
        int u;
        DeQueue(Q, u); // 取出队头元素

        // 遍历u的所有邻接点
        int w = FirstNeighbor(G, u);
        while (w != -1)
        {
            if (!visited[w])
            {
                printf("%c ", G.vertices[w].data);
                visited[w] = true;
                EnQueue(Q, w);
            }
            w = NextNeighbor(G, u, w); // 获取下一个邻接点
        }
    }
}

/**
 * @brief 广度优先遍历图
 *
 * @param G 图结构体
 */
void BFSTraverse(ALGraph G)
{
    bool visited[MaxVertexNum] = {false}; // 初始化访问数组
    printf("BFS Traversal:\n");
    for (int i = 0; i < G.vexnum; i++)
    {
        if (!visited[i])
        {
            BFS(G, i, visited); // 对未访问的连通分量调用BFS
        }
    }
    printf("\n");
}

/**
 * @brief 深度优先搜索核心函数
 *
 * @param G 图结构体
 * @param v 起始顶点索引
 * @param visited 访问标记数组
 */
void DFS(ALGraph G, int v, bool visited[])
{
    printf("%c ", G.vertices[v].data); // 访问顶点
    visited[v] = true;

    // 遍历v的所有邻接点
    int w = FirstNeighbor(G, v);
    while (w != -1)
    {
        if (!visited[w])
        {
            DFS(G, w, visited); // 递归访问邻接点
        }
        w = NextNeighbor(G, v, w); // 获取下一个邻接点
    }
}

/**
 * @brief 深度优先遍历图
 *
 * @param G 图结构体
 */
void DFSTraverse(ALGraph G)
{
    bool visited[MaxVertexNum] = {false}; // 初始化访问数组
    printf("DFS Traversal:\n");
    for (int i = 0; i < G.vexnum; i++)
    {
        if (!visited[i])
        {
            DFS(G, i, visited); // 对未访问的连通分量调用DFS
        }
    }
    printf("\n");
}


////////////////////////////////////////////////////////

/**
 * @brief 创建图的初始结构
 *
 * @param G 图结构体指针
 */
void CreateGraph2(ALGraph &G2)
{
    // 创建图
    char vertices2[] = {'A', 'B', 'C', 'D', 'E'};
    G2.vexnum = 5;
    G2.arcnum = 0;
    for (int i = 0; i < G2.vexnum; i++)
    {
        G2.vertices[i].data = vertices2[i];
        G2.vertices[i].first = NULL;
    }

    // 添加预定义的边和权值
    char edges2[][2] = {
        {'A', 'B'}, {'A', 'C'}, {'A', 'D'}, {'A', 'E'}, {'B', 'A'}, {'B', 'C'}, {'B', 'D'}, {'C', 'A'}, {'C', 'B'}, {'C', 'D'}, {'C', 'E'}, {'D', 'A'}, {'D', 'B'}, {'D', 'E'}, {'E', 'B'}, {'E', 'C'}, {'E', 'D'}};
    int weights2[] = {10, 5, 3, 1, 9, 8, 2, 7, 4, 1, 12, 8, 2, 4, 2, 1, 5};

    int num_edges2 = sizeof(edges2) / sizeof(edges2[0]);
    for (int k = 0; k < num_edges2; k++)
    {
        AddEdge(&G2, edges2[k][0], edges2[k][1], weights2[k]);
    }
}

void PrintDijkstraPath(int start, int v, int path[], ALGraph G);

/**
 * @brief Dijkstra算法实现单源最短路径
 *
 * @param G 图结构体
 * @param start 起始顶点索引
 */
void Dijkstra(ALGraph G, int start)
{
    // 参数有效性检查
    if (start < 0 || start >= G.vexnum)
    {
        printf("错误：起始顶点索引超出范围\n");
        return;
    }

    int n = G.vexnum;
    bool final[MaxVertexNum]; // 标记顶点是否已找到最短路径
    int dist[MaxVertexNum];   // 最短路径长度数组
    int path[MaxVertexNum];   // 前驱顶点数组

    // 初始化各数组
    for (int v = 0; v < n; v++)
    {
        final[v] = false;                 // 初始化所有顶点未找到最短路径
        dist[v] = GetWeight(G, start, v); // 初始化距离数组
        if (dist[v] != INT_MAX)
        {                    // 如果起点到v存在直接路径
            path[v] = start; // 可达顶点的前驱初始化为起点
        }
        else
        {
            path[v] = -1; // 不可达顶点的前驱初始化为-1
        }
    }
    dist[start] = 0;     // 起点到自身距离为0
    final[start] = true; // 起点最先加入集合

    // 主循环：重复n-1次查找剩余顶点
    for (int i = 1; i < n; i++)
    {
        int min_dist = INT_MAX; // 当前最短距离
        int u = -1;             // 最短距离顶点的索引

        // 选择当前未处理的最小距离顶点
        for (int v = 0; v < n; v++)
        {
            if (!final[v] && dist[v] < min_dist)
            {
                min_dist = dist[v]; // 更新最短距离
                u = v;              // 更新最短距离顶点索引
            }
        }

        if (u == -1)
            break;       // 没有找到可到达的顶点，结束循环
        final[u] = true; // 将u加入已确定集合

        // 遍历u的所有邻接点并更新最短路径
        int w = FirstNeighbor(G, u);
        while (w != -1)
        {
            int weight = GetWeight(G, u, w); // 获取u到w的边权值
            // 如果存在更短路径
            if (!final[w] &&
                dist[u] != INT_MAX &&
                dist[u] + weight < dist[w])
            {
                dist[w] = dist[u] + weight; // 更新距离
                path[w] = u;                // 更新前驱
            }
            w = NextNeighbor(G, u, w); // 获取下一个邻接点
        }
    }

    // 输出结果(直接输入dist和path数组) 
    printf("dist数组：");
    for (int v = 0; v < n; v++)
        printf(" %2d ", dist[v]);
    printf("\n");
    printf("path数组：");
    for (int v = 0; v < n; v++)
        printf(" %2d ", path[v]);
    // 输出结果（可视化）
    printf("\nDijkstra算法结果（从顶点%c）:\n", G.vertices[start].data);
    printf("目标顶点 | 最短距离 | 前驱顶点\n");
    for (int v = 0; v < n; v++)
    {
        printf("   %c    |", G.vertices[v].data);
        if (dist[v] == INT_MAX)
        {
            printf("   INF    |");
        }
        else
        {
            printf("   %3d    |", dist[v]);
        }
        if (path[v] == -1)
        {
            printf("   -   ");
        }
        else
        {
            printf("   %c   ", G.vertices[path[v]].data);
        }
        printf("\n");
    }

    // 输出完整路径
    printf("\n完整路径：\n");
    for (int v = 0; v < n; v++)
    {
        if (v != start)
        {
            printf("从%c到%c的最短路径: ", G.vertices[start].data, G.vertices[v].data);
            if (dist[v] == INT_MAX)
            {
                printf("不可达\n");
            }
            else
            {
                PrintDijkstraPath(start, v, path, G);
                printf(" (距离: %d)\n", dist[v]);
            }
        }
    }
}

/**
 * @brief 递归打印Dijkstra路径
 *
 * @param start 起始顶点索引
 * @param v 当前顶点索引
 * @param path 前驱数组
 * @param G 图结构体
 */
void PrintDijkstraPath(int start, int v, int path[], ALGraph G)
{
    if (path[v] == -1 || v == start)
    {
        printf("%c", G.vertices[start].data);
    }
    else
    {
        PrintDijkstraPath(start, path[v], path, G); // 递归打印前驱路径
        printf(" -> %c", G.vertices[v].data);
    }
}

/**
 * @brief Floyd算法实现所有顶点对的最短路径
 *
 * @param G 图结构体
 */
void Floyd(ALGraph G)
{
    int A[MaxVertexNum][MaxVertexNum];    // 最短路径长度矩阵
    int path[MaxVertexNum][MaxVertexNum]; // 中转点矩阵
    int n = G.vexnum;                     // 顶点数

    // 初始化距离矩阵和路径矩阵
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                A[i][j] = 0; // 对角线初始化为0
            }
            else
            {
                A[i][j] = GetWeight(G, i, j); // 从邻接表获取初始距离
            }
            path[i][j] = (A[i][j] != INT_MAX) ? j : -1; // 直接可达标记为j
        }
    }

    // 动态规划三重循环
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // 如果经过k点的路径更短
                if (A[i][k] != INT_MAX && A[k][j] != INT_MAX &&
                    A[i][j] > A[i][k] + A[k][j])
                {
                    A[i][j] = A[i][k] + A[k][j]; // 更新最短距离
                    path[i][j] = path[i][k];     // 更新中转点
                }
            }
        }
    }

    // 输出结果矩阵
    printf("\nFloyd算法结果：\n");
    printf("最短路径长度矩阵A：\n  ");
    for (int i = 0; i < n; i++)
    {
        printf("%4c", G.vertices[i].data);
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%c ", G.vertices[i].data);
        for (int j = 0; j < n; j++)
        {
            if (A[i][j] == INT_MAX)
            {
                printf(" INF");
            }
            else
            {
                printf("%4d", A[i][j]);
            }
        }
        printf("\n");
    }

    // 输出完整路径
    printf("\n所有顶点对的最短路径：\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                printf("%c到%c的最短路径: ", G.vertices[i].data, G.vertices[j].data);
                if (A[i][j] == INT_MAX)
                {
                    printf("不可达\n");
                }
                else
                {
                    printf("%c", G.vertices[i].data);
                    int k = i;
                    while (k != j)
                    {
                        k = path[k][j];
                        printf(" -> %c", G.vertices[k].data);
                    }
                    printf(" (距离: %d)\n", A[i][j]);
                }
            }
        }
    }
}

/**
 * @brief 主函数
 *
 * @return int 程序退出状态码
 */
int main()
{
    ALGraph G;
    // 创建图
    CreateGraph(&G);
    // 插入新顶点J
    InsertVertex(&G, 'J');
    // 添加边<J,G>
    AddEdge(&G, 'J', 'G', 6);

    // 执行遍历
    BFSTraverse(G); // BFS Traversal: A B C F G E D J 
    DFSTraverse(G); // DFS Traversal: A B E C D F G J 

    printf("\n------------------------------------------------\n");

    // 图的最短路径问题
    ALGraph G2;

    CreateGraph2(G2);   // 创建图G2

    // Dijkstra算法测试（从每个顶点开始）
    for (int start = 0; start < G2.vexnum; start++)
    {
        printf("\nDijkstra算法结果（从顶点%c）:\n", G2.vertices[start].data);
        Dijkstra(G2, start); // 从顶点start开始
    }

    printf("\n------------------------------------------------\n");

    // Floyd算法测试
    Floyd(G2);

    return 0;
}

/*
Dijkstra算法结果（从顶点A）:
dist数组：  0   3   2   3   1
path数组： -1   4   4   0   0
Dijkstra算法结果（从顶点A）:
目标顶点 | 最短距离 | 前驱顶点
   A    |     0    |   -
   B    |     3    |   E
   C    |     2    |   E
   D    |     3    |   A
   E    |     1    |   A

完整路径：
从A到B的最短路径: A -> E -> B (距离: 3)
从A到C的最短路径: A -> E -> C (距离: 2)
从A到D的最短路径: A -> D (距离: 3)
从A到E的最短路径: A -> E (距离: 1)

Dijkstra算法结果（从顶点B）:
dist数组：  9   0   7   2   6
path数组：  1  -1   4   1   3
Dijkstra算法结果（从顶点B）:
目标顶点 | 最短距离 | 前驱顶点
   A    |     9    |   B
   B    |     0    |   -
   C    |     7    |   E
   D    |     2    |   B
   E    |     6    |   D

完整路径：
从B到A的最短路径: B -> A (距离: 9)
从B到C的最短路径: B -> D -> E -> C (距离: 7)
从B到D的最短路径: B -> D (距离: 2)
从B到E的最短路径: B -> D -> E (距离: 6)

Dijkstra算法结果（从顶点C）:
dist数组：  7   3   0   1   5
path数组：  2   3  -1   2   3
Dijkstra算法结果（从顶点C）:
目标顶点 | 最短距离 | 前驱顶点
   A    |     7    |   C
   B    |     3    |   D
   C    |     0    |   -
   D    |     1    |   C
   E    |     5    |   D

完整路径：
从C到A的最短路径: C -> A (距离: 7)
从C到B的最短路径: C -> D -> B (距离: 3)
从C到D的最短路径: C -> D (距离: 1)
从C到E的最短路径: C -> D -> E (距离: 5)

Dijkstra算法结果（从顶点D）:
dist数组：  8   2   5   0   4
path数组：  3   3   4  -1   3
Dijkstra算法结果（从顶点D）:
目标顶点 | 最短距离 | 前驱顶点
   A    |     8    |   D
   B    |     2    |   D
   C    |     5    |   E
   D    |     0    |   -
   E    |     4    |   D

完整路径：
从D到A的最短路径: D -> A (距离: 8)
从D到B的最短路径: D -> B (距离: 2)
从D到C的最短路径: D -> E -> C (距离: 5)
从D到E的最短路径: D -> E (距离: 4)

Dijkstra算法结果（从顶点E）:
dist数组：  8   2   1   2   0
path数组：  2   4   4   2  -1
Dijkstra算法结果（从顶点E）:
目标顶点 | 最短距离 | 前驱顶点
   A    |     8    |   C
   B    |     2    |   E
   C    |     1    |   E
   D    |     2    |   C
   E    |     0    |   -

完整路径：
从E到A的最短路径: E -> C -> A (距离: 8)
从E到B的最短路径: E -> B (距离: 2)
从E到C的最短路径: E -> C (距离: 1)
从E到D的最短路径: E -> C -> D (距离: 2)

------------------------------------------------

Floyd算法结果：
最短路径长度矩阵A：
     A   B   C   D   E
A    0   3   2   3   1
B    9   0   7   2   6
C    7   3   0   1   5
D    8   2   5   0   4
E    8   2   1   2   0

所有顶点对的最短路径：
A到B的最短路径: A -> E -> B (距离: 3)
A到C的最短路径: A -> E -> C (距离: 2)
A到D的最短路径: A -> D (距离: 3)
A到E的最短路径: A -> E (距离: 1)
B到A的最短路径: B -> A (距离: 9)
B到C的最短路径: B -> D -> E -> C (距离: 7)
B到D的最短路径: B -> D (距离: 2)
B到E的最短路径: B -> D -> E (距离: 6)
C到A的最短路径: C -> A (距离: 7)
C到B的最短路径: C -> D -> B (距离: 3)
C到D的最短路径: C -> D (距离: 1)
C到E的最短路径: C -> D -> E (距离: 5)
D到A的最短路径: D -> A (距离: 8)
D到B的最短路径: D -> B (距离: 2)
D到C的最短路径: D -> E -> C (距离: 5)
D到E的最短路径: D -> E (距离: 4)
E到A的最短路径: E -> C -> A (距离: 8)
E到B的最短路径: E -> B (距离: 2)
E到C的最短路径: E -> C (距离: 1)
E到D的最短路径: E -> C -> D (距离: 2)

*/
