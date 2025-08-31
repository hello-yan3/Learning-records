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

#define MaxVertexNum 10 // 顶点数目的最大值

// ==================== 数据结构定义 ====================
// 队列结构定义
typedef struct
{
    int data[MaxVertexNum]; // 存储队列元素（顶点索引）
    int front;              // 队头指针
    int rear;               // 队尾指针
} Queue;

// 图结构体定义
typedef struct
{
    char Vex[MaxVertexNum];               // 顶点表
    int Edge[MaxVertexNum][MaxVertexNum]; // 邻接矩阵，边表
    int vexnum, arcnum;                   // 图的当前顶点数和边数/弧数
} MGraph;

// ==================== 函数声明 ====================
int GetVertexIndex(MGraph G, char x);
void InitQueue(Queue *Q);
int EnQueue(Queue *Q, int x);
int DeQueue(Queue *Q, int *x);
int InsertVertex(MGraph *G, char x);
int AddEdge(MGraph *G, char x, char y, int weight);
int FirstNeighbor(MGraph G, int x);
int NextNeighbor(MGraph G, int x, int y);
void CreateGraph(MGraph *G);
void BFS(MGraph G, int v, bool visited[]);
void BFSTraverse(MGraph G);
void DFS(MGraph G, int v, bool visited[]);
void DFSTraverse(MGraph G);

// ==================== 函数实现 ====================
// ==================== 队列函数 ====================
/**
 * @brief 初始化队列
 *
 * @param Q 队列指针
 */
void InitQueue(Queue *Q)
{
    Q->front = 0;
    Q->rear = 0;
}

/**
 * @brief 入队操作
 *
 * @param Q 队列指针
 * @param x 要入队的顶点索引
 * @return int 入队成功返回1，队列满返回0
 */
int EnQueue(Queue *Q, int x)
{
    if ((Q->rear + 1) % MaxVertexNum == Q->front)
    {
        return 0; // 队列满
    }
    Q->data[Q->rear] = x;
    Q->rear = (Q->rear + 1) % MaxVertexNum;
    return 1;
}

/**
 * @brief 出队操作
 *
 * @param Q 队列指针
 * @param x 出队的顶点索引存储地址
 * @return int 出队成功返回1，队列空返回0
 */
int DeQueue(Queue *Q, int *x)
{
    if (Q->front == Q->rear)
    {
        return 0; // 队列空
    }
    *x = Q->data[Q->front];
    Q->front = (Q->front + 1) % MaxVertexNum;
    return 1;
}

// ==================== 图操作函数 ====================
/**
 * @brief 查找顶点在顶点表中的索引
 *
 * @param G 图结构体
 * @param x 要查找的顶点字符
 * @return int 返回顶点索引，不存在返回-1
 */
int GetVertexIndex(MGraph G, char x)
{
    for (int i = 0; i < G.vexnum; i++)
    {
        if (G.Vex[i] == x)
        {
            return i;
        }
    }
    return -1;
}

/**
 * @brief 插入顶点x到图G中
 *
 * @param G 图结构体指针
 * @param x 要插入的顶点字符
 * @return int 成功插入返回1，顶点已存在或图满返回0
 */
int InsertVertex(MGraph *G, char x)
{
    int index = GetVertexIndex(*G, x);
    if (index != -1)
    {
        return 0; // 顶点已存在
    }
    if (G->vexnum >= MaxVertexNum)
    {
        return 0; // 顶点数超过上限
    }
    G->Vex[G->vexnum] = x;
    G->vexnum++;
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
int AddEdge(MGraph *G, char x, char y, int weight)
{
    int i = GetVertexIndex(*G, x);
    int j = GetVertexIndex(*G, y);
    if (i == -1 || j == -1)
    {
        return 0; // 顶点不存在
    }
    if (G->Edge[i][j] != INT_MAX)
    {
        return 0; // 边已存在
    }
    G->Edge[i][j] = weight; // 使用指定权值
    G->arcnum++;
    return 1;
}

/**
 * @brief 创建图的初始结构
 *
 * @param G 图结构体指针
 */
void CreateGraph(MGraph *G)
{
    // 初始化顶点表
    char vertices[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    G->vexnum = 7;
    G->arcnum = 0;
    for (int i = 0; i < G->vexnum; i++)
    {
        G->Vex[i] = vertices[i];
    }
    // 初始化邻接矩阵为INT_MAX
    for (int i = 0; i < MaxVertexNum; i++)
    {
        for (int j = 0; j < MaxVertexNum; j++)
        {
            G->Edge[i][j] = INT_MAX;
        }
    }
    // 顶点到自身距离为0
    for (int i = 0; i < MaxVertexNum; i++)
    {
        G->Edge[i][i] = 0;
    }
    // 添加预定义的边
    char edges[][2] = {
        {'A', 'B'}, {'A', 'C'}, {'A', 'F'}, {'A', 'G'}, {'B', 'A'}, {'B', 'E'}, {'C', 'A'}, {'C', 'B'}, {'C', 'D'}, {'C', 'F'}, {'D', 'B'}, {'D', 'E'}, {'F', 'A'}, {'F', 'E'}, {'F', 'G'}, {'G', 'D'}};
    // 添加预定义的权值
    int Weight[] = {1, 4, 3, 1, 5, 6, 5, 3, 4, 4,
                    2, 3, 2, 6, 2, 1};

    int num_edges = sizeof(edges) / sizeof(edges[0]);
    for (int k = 0; k < num_edges; k++)
    {
        char x = edges[k][0];
        char y = edges[k][1];
        int i = GetVertexIndex(*G, x);
        int j = GetVertexIndex(*G, y);
        if (i == -1 || j == -1)
            continue;
        G->Edge[i][j] = Weight[k];
        G->arcnum++;
    }
}

/**
 * @brief 获取顶点x的第一个邻接点
 *
 * @param G 图结构体
 * @param x 顶点索引
 * @return int 返回第一个邻接点索引，无邻接点返回-1
 */
int FirstNeighbor(MGraph G, int x)
{
    if (x < 0 || x >= G.vexnum)
    {
        return -1; // 顶点无效
    }
    for (int i = 0; i < G.vexnum; i++)
    {
        if (G.Edge[x][i] != INT_MAX  && G.Edge[x][i] != 0)
        {
            return i;
        }
    }
    return -1;
}

/**
 * @brief 获取顶点x相对于y的下一个邻接点
 *
 * @param G 图结构体
 * @param x 当前顶点索引
 * @param y 当前邻接点索引
 * @return int 返回下一个邻接点索引，无更多邻接点返回-1
 */
int NextNeighbor(MGraph G, int x, int y)
{
    if (x < 0 || x >= G.vexnum || y < 0 || y >= G.vexnum)
    {
        return -1;
    }
    for (int i = y + 1; i < G.vexnum; i++)
    {
        if (G.Edge[x][i] != INT_MAX  && G.Edge[x][i] != 0)
        {
            return i;
        }
    }
    return -1;
}

/**
 * @brief 广度优先搜索核心函数
 *
 * @param G 图结构体
 * @param v 起始顶点索引
 * @param visited 访问标记数组
 */
void BFS(MGraph G, int v, bool visited[])
{
    Queue Q; // 队列
    InitQueue(&Q);
    printf("%c ", G.Vex[v]); // 访问顶点
    visited[v] = true;
    EnQueue(&Q, v);

    while (Q.front != Q.rear) // 队列不空
    {
        int u; // 出队的顶点索引存储地址
        DeQueue(&Q, &u);
        // 遍历u的所有邻接点
        int w = FirstNeighbor(G, u); // 获取顶点u的第一个邻接点，w是顶点索引
        while (w != -1)
        {
            if (!visited[w])
            {
                printf("%c ", G.Vex[w]);
                visited[w] = true;
                EnQueue(&Q, w);
            }
            w = NextNeighbor(G, u, w); // 获取顶点u相对于w的下一个邻接点
        }
    }
}

/**
 * @brief 广度优先遍历图
 *
 * @param G 图结构体
 */
void BFSTraverse(MGraph G)
{
    bool visited[MaxVertexNum];
    for (int i = 0; i < G.vexnum; i++)
    {
        visited[i] = false;
    }
    printf("BFS Traversal:\n");
    for (int i = 0; i < G.vexnum; i++)
    {
        if (!visited[i])
        {
            BFS(G, i, visited);
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
void DFS(MGraph G, int v, bool visited[])
{
    printf("%c ", G.Vex[v]);
    visited[v] = true;
    int w = FirstNeighbor(G, v); // 获取顶点v的第一个邻接点，w是顶点索引
    while (w != -1)
    {
        if (!visited[w])
        {
            DFS(G, w, visited);
        }
        w = NextNeighbor(G, v, w); // 获取顶点v相对于w的下一个邻接点
    }
}

/**
 * @brief 深度优先遍历图
 *
 * @param G 图结构体
 */
void DFSTraverse(MGraph G)
{
    bool visited[MaxVertexNum];
    for (int i = 0; i < G.vexnum; i++)
    {
        visited[i] = false;
    }
    printf("DFS Traversal:\n");
    for (int i = 0; i < G.vexnum; i++)
    {
        if (!visited[i])
        {
            DFS(G, i, visited);
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
void CreateGraph2(MGraph *G)
{
    // 初始化顶点表
    char vertices[] = {'A', 'B', 'C', 'D', 'E'};
    G->vexnum = 5;
    G->arcnum = 0;
    for (int i = 0; i < G->vexnum; i++)
    {
        G->Vex[i] = vertices[i];
    }
    // 初始化邻接矩阵为INT_MAX
    for (int i = 0; i < MaxVertexNum; i++)
    {
        for (int j = 0; j < MaxVertexNum; j++)
        {
            G->Edge[i][j] = INT_MAX;
        }
    }
    // 顶点到自身距离为0
    for (int i = 0; i < MaxVertexNum; i++)
    {
        G->Edge[i][i] = 0;
    }
    // 添加预定义的边
    char edges[][2] = {
        {'A', 'B'}, {'A', 'C'}, {'A', 'D'}, {'A', 'E'}, {'B', 'A'}, {'B', 'C'}, {'B', 'D'}, {'C', 'A'}, {'C', 'B'}, {'C', 'D'}, {'C', 'E'}, {'D', 'A'}, {'D', 'B'}, {'D', 'E'}, {'E', 'B'}, {'E', 'C'}, {'E', 'D'}};
    // 添加预定义的权值
    int Weight[] = {10, 5, 3, 1, 9, 8, 2, 7, 4, 1,
                    12, 8, 2, 4, 2, 1, 5};

    int num_edges = sizeof(edges) / sizeof(edges[0]);
    for (int k = 0; k < num_edges; k++)
    {
        char x = edges[k][0];
        char y = edges[k][1];
        int i = GetVertexIndex(*G, x);
        int j = GetVertexIndex(*G, y);
        if (i == -1 || j == -1)
            continue;
        G->Edge[i][j] = Weight[k];
        G->arcnum++;
    }
}

// 前向声明
void PrintDijkstraPath(int start, int v, int path[], MGraph G);
void PrintFloydPath(int i, int j, int path[][MaxVertexNum], MGraph G);

/**
 * @brief Dijkstra算法实现单源最短路径
 *
 * @param G 图结构体
 * @param start 起始顶点索引
 */
void Dijkstra(MGraph G, int start)
{
    // 参数有效性检查
    if (start < 0 || start >= G.vexnum)
    {
        printf("错误：起始顶点索引超出范围\n");
        return;
    }

    int n = G.vexnum;         // n = 顶点数
    bool final[MaxVertexNum]; // 标记顶点是否已找到最短路径
    int dist[MaxVertexNum];   // 最短路径长度数组
    int path[MaxVertexNum];   // 前驱顶点数组

    // 初始化各数组
    for (int v = 0; v < n; v++)     // v遍历用的临时变量，指代各个顶点
    {
        final[v] = false;           // 初始化所有顶点未找到最短路径
        dist[v] = G.Edge[start][v]; // 初始化距离数组
        if (dist[v] != INT_MAX)     // 如果由strat顶点到v顶点，存在路径
        {
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
        int min_dist = INT_MAX;    // min_dist为当前最短距离
        int u = -1;                // 最短距离顶点的索引

        // 选择当前未处理的最小距离顶点
        for (int v = 0; v < n; v++)  // v遍历用的临时变量，指代各个顶点
        {
            if (!final[v] && dist[v] < min_dist)   // 如果当前顶点v未找到最短路径 且 start到顶点v的距离 小于 min_dist
            {
                min_dist = dist[v]; // 更新最短距离
                u = v;              // 更新最短距离顶点的索引
            }
        }

        // 如果没有找到可到达的顶点，结束循环
        if (u == -1)
            break;

        final[u] = true; // 将u加入已确定集合(start到u的最短路径已找到)

        // 更新所有顶点的最短路径
        for (int v = 0; v < n; v++)  // v遍历用的临时变量，指代各个顶点
        {
            // 如果顶点未确定且存在更短路径
            if (!final[v] &&                             // 如果当前顶点v未找到最短路径
                G.Edge[u][v] != INT_MAX &&               // 如果顶点u到顶点v存在路径
                dist[u] != INT_MAX &&                    // 如果顶点start到顶点u存在路径
                dist[u] + G.Edge[u][v] < dist[v])        // 如果顶点start到顶点u的路径长度 + 顶点u到顶点v的路径长度 < 顶点start到顶点v的路径长度
            {

                dist[v] = dist[u] + G.Edge[u][v];     // 更新距离
                path[v] = u;                          // 更新前驱
            }
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
    // 输出结果(可视化dist和path数组) 
    printf("\nDijkstra算法结果（从顶点%c）:\n", G.Vex[start]);
    printf("目标顶点 | 最短距离 | 前驱顶点\n");
    for (int v = 0; v < n; v++)
    {
        printf("   %c    |", G.Vex[v]);
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
            printf("   %c   ", G.Vex[path[v]]);
        }
        printf("\n");
    }

    // 输出完整路径
    printf("\n完整路径：\n");
    for (int v = 0; v < n; v++)
    {
        if (v != start)
        {
            printf("从%c到%c的最短路径: ", G.Vex[start], G.Vex[v]);
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
void PrintDijkstraPath(int start, int v, int path[], MGraph G)
{
    if (path[v] == -1 || v == start)
    {
        printf("%c", G.Vex[start]);
    }
    else
    {
        PrintDijkstraPath(start, path[v], path, G); // 递归打印前驱路径
        printf(" -> %c", G.Vex[v]);
    }
}

/**
 * @brief Floyd算法实现所有顶点对的最短路径
 *
 * @param G 图结构体
 */
void Floyd(MGraph G)
{
    int A[MaxVertexNum][MaxVertexNum];        // 数组A，表示各顶点间的最短路径长度
    int path[MaxVertexNum][MaxVertexNum];     // 数组path，表示各顶点间的中转点
    int n = G.vexnum;           // n = 顶点数

    // 初始化距离矩阵和路径矩阵
    // 由顶点i到顶点j的路径长度为A[i][j]，path[i][j]表示从i到j的中转点
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            A[i][j] = G.Edge[i][j]; // 复制原始邻接矩阵（初始最短路径长度就是邻接矩阵）
            if (G.Edge[i][j] == INT_MAX)
            {
                path[i][j] = -1; // 不可达路径标记为-1
            }
            else
            {
                path[i][j] = j;  // 直接可达标记为终点
            }
        }
    }

    // 动态规划三重循环
    for (int k = 0; k < n; k++)   // 考虑k作为中转点
    { 
        // 由顶点i到顶点j的路径长度为A[i][j]，path[i][j]表示从i到j的中转点
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // 如果经过k点的路径更短且不存在溢出风险
                if (A[i][k] != INT_MAX &&            // 如果顶点i到顶点k存在路径
                    A[k][j] != INT_MAX &&            // 如果顶点k到顶点j存在路径
                    A[i][j] > A[i][k] + A[k][j])     // 如果顶点i到顶点j的路径长度 > 顶点i到顶点k的路径长度 + 顶点k到顶点j的路径长度
                {

                    A[i][j] = A[i][k] + A[k][j];     // 更新最短距离
                    path[i][j] = path[i][k];         // 更新中转点
                }
            }
        }
    }

    // 输出结果矩阵
    printf("\nFloyd算法结果：\n");
    printf("最短路径长度矩阵A：\n");
    printf("  ");
    for (int i = 0; i < n; i++)
    {
        printf("%4c", G.Vex[i]);
    }
    printf("\n");

    for (int i = 0; i < n; i++)
    {
        printf("%c ", G.Vex[i]);
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

    printf("\n路径中转矩阵path：\n");
    printf(" ");
    for (int i = 0; i < n; i++)
    {
        printf("%4c", G.Vex[i]);
    }
    printf("\n");

    for (int i = 0; i < n; i++)
    {
        printf("%c ", G.Vex[i]);
        for (int j = 0; j < n; j++)
        {
            if (path[i][j] == -1)
            {
                printf("  - ");
            }
            else
            {
                printf("  %c ", G.Vex[path[i][j]]);
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
                printf("%c到%c的最短路径: ", G.Vex[i], G.Vex[j]);
                if (A[i][j] == INT_MAX)
                {
                    printf("不可达\n");
                }
                else
                {
                    printf("%c", G.Vex[i]);
                    PrintFloydPath(i, j, path, G);
                    printf(" (距离: %d)\n", A[i][j]);
                }
            }
        }
    }
}

/**
 * @brief 递归打印Floyd路径
 *
 * @param i 起始顶点索引
 * @param j 终止顶点索引
 * @param path 中转矩阵
 * @param G 图结构体
 */
void PrintFloydPath(int i, int j, int path[][MaxVertexNum], MGraph G)
{
    if (path[i][j] == j)
    { // 直接可达
        printf(" -> %c", G.Vex[j]);
        return;
    }

    // 递归打印i到k的路径
    PrintFloydPath(i, path[i][j], path, G);
    // 递归打印k到j的路径
    PrintFloydPath(path[i][j], j, path, G);
}

/**
 * @brief 主函数
 *
 * @return int 程序退出状态码
 */
int main()
{
    MGraph G;

    // 创建图
    CreateGraph(&G);

    // 插入新顶点J
    InsertVertex(&G, 'J');

    // 添加边<J,A>
    AddEdge(&G, 'J', 'G', 6);

    // 执行遍历
    BFSTraverse(G); // BFS Traversal: A B C F G E D J
    DFSTraverse(G); // DFS Traversal: A B E C D F G J

    printf("\n------------------------------------------------\n");

    // 图的最短路径问题
    MGraph G2;

    // 创建图
    CreateGraph2(&G2);

    // Dijkstra算法测试（从顶点start开始）
    for(int start = 0; start < G2.vexnum; start++)
    {
        printf("\nDijkstra算法结果（从顶点%c）:\n", G2.Vex[start]);
        Dijkstra(G2, start);    // 从顶点start开始
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

-------------------------------------------------

Floyd算法结果：
最短路径长度矩阵A：
     A   B   C   D   E
A    0   3   2   3   1
B    9   0   7   2   6
C    7   3   0   1   5
D    8   2   5   0   4
E    8   2   1   2   0

路径中转矩阵path：
    A   B   C   D   E
A   A   E   E   D   E
B   A   B   D   D   D
C   A   D   C   D   D
D   A   B   E   D   E
E   C   B   C   C   E

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