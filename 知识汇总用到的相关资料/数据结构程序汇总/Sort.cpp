/**
 * @brief 排序
 * @attention：
 * 排序的基本概念：
 * 1. 排序：重新排列表中的元素，使表中元素满足按关键字有序的过程。
 * 2. 输入：n个记录 R1, R2, ... , Rn 对应的关键字为 k1, k2, ... , kn
 * 3. 输出：输入序列的一个重排 R1′, R2′, ... , Rn′ ，使得 k1′ ≤ k2′ ≤ ... ≤ kn′
 * 4. 算法的稳定性：关键字相同的元素在使用某一排序算法之后相对位置不变，则称这个排序算法是稳定的，否则称其为不稳定的。稳定的排序算法不一定比不稳定的排序算法要好。
 * 5. 排序算法的评价指标：时间复杂度、空间复杂度、稳定性。
 * 常见的排序算法：
 * * 插入排序：
 * * - 直接插入排序：
 * * - 希尔排序：
 * * 选择排序：
 * * - 选择排序：
 * * - 堆排序：
 * * 交换排序：
 * * - 冒泡排序：
 * * - 快速排序：
 * * 归并排序：
 * * 基数排序：
 */

/***********************排序***********************/

#include <stdio.h>

#define ARR_LEN 255 /*数组长度上限*/

/*数据交换*/
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*获取数字的位数*/
int figure(int num)
{
    int count = 1;
    int temp = num / 10;

    while (temp != 0)
    {
        count++;
        temp /= 10;
    }

    return count;
}

/*查询数组中的最大数*/
int max(int *a, int n)
{
    int max = a[0];
    int i;

    for (i = 1; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }

    return max;
}

/**************************************/
/* 插入排序 */
void insertion_sort(int arr[], int len)
{
    int i, j, key;
    // 3 4 2 1
    for (i = 1; i < len; i++)
    {
        /*
        第一次循环：i=1, j=0, 
        如果 arr[0]>arr[1]  交换：  arr[1]=arr[0]; arr[0]=arr[1]
        第二次循环：i=2, j=1, key=arr[2]
        如果 arr[1]>arr[2] 
        arr[2]=arr[1]    如果 arr[0]>arr[2]     arr[1]=arr[0]       arr[0]=arr[2]
        arr[2]=arr[1]    如果 arr[0]<arr[2]     arr[1]=arr[2]   ……
        */
        key = arr[i];
        j = i - 1;
        while ((j >= 0) && (arr[j] > key))
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

/* 希尔排序 */
void shell_sort(int arr[], int len)
{
    int increasement = len;
    int i, j, k;
    do
    {
        // 确定分组的增量
        increasement = increasement / 3 + 1;
        for (i = 0; i < increasement; i++)
        {
            for (j = i + increasement; j < len; j += increasement)
            {
                if (arr[j] < arr[j - increasement])
                {
                    int temp = arr[j];
                    for (k = j - increasement; k >= 0 && temp < arr[k]; k -= increasement)
                    {
                        arr[k + increasement] = arr[k];
                    }
                    arr[k + increasement] = temp;
                }
            }
        }
    } while (increasement > 1);
}

/* 选择排序 */
void selection_sort(int arr[], int len)
{
    int i, j;
    for (i = 0; i < len - 1; i++)
    {
        int min = i;
        for (j = i + 1; j < len; j++)
        { //  遍历未排序的元素
            if (arr[j] < arr[min])
            {            //  找到目前最小值
                min = j; // 记录最小值
            }
        }
        swap(&arr[min], &arr[i]); // 做交换
        /*if (index != i)  // 不用自定义函数时可以用选择下面方式进行交换
        {
            temp = arr[i];
            arr[i] = arr[index];
            arr[index] = temp;
        }*/
    }
}

/* 冒泡排序 */
void BubbleSort(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp;
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// 快速排序
void QuickSort(int arr[], int start, int end)
{
    if (start >= end)
        return;
    int i = start;
    int j = end;
    // 基准数
    int baseval = arr[start];
    while (i < j)
    {
        // 从右向左找比基准数小的数
        while (i < j && arr[j] >= baseval)
        {
            j--;
        }
        if (i < j)
        {
            arr[i] = arr[j];
            i++;
        }
        // 从左向右找比基准数大的数
        while (i < j && arr[i] < baseval)
        {
            i++;
        }
        if (i < j)
        {
            arr[j] = arr[i];
            j--;
        }
    }
    // 把基准数放到i的位置
    arr[i] = baseval;
    // 递归
    QuickSort(arr, start, i - 1);
    QuickSort(arr, i + 1, end);
}

void max_heapify(int arr[], int start, int end)
{
    // 建立父节点指标和子节点指标
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end)
    {                                                  // 若子节点指标在范围內才做比较
        if (son + 1 <= end && arr[son] < arr[son + 1]) // 先比较两个子节点大小，选择最大的
            son++;
        if (arr[dad] > arr[son]) // 如果父节点大于子节点代表调整完毕，直接跳出函数
            return;
        else
        { // 否则交换父子內容再继续子节点和父节点比较
            swap(&arr[dad], &arr[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}

// 堆排序
void heap_sort(int arr[], int len)
{
    int i;
    // 初始化，i从最后一个父节点开始调整
    for (i = len / 2 - 1; i >= 0; i--)
        max_heapify(arr, i, len - 1);
    // 先将第一个元素和已排好元素前一位做交换，再重新调整，直到排序完毕
    for (i = len - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);
        max_heapify(arr, 0, i - 1);
    }
}

// 归并排序
void MergeSort(int arr[], int start, int end, int *temp) // start和end分别是左边界和右边界
{
    if (start >= end)
        return;
    int mid = (start + end) / 2;
    MergeSort(arr, start, mid, temp);
    MergeSort(arr, mid + 1, end, temp);

    // 合并两个有序序列
    int length = 0; // 表示辅助空间有多少个元素
    int i_start = start;
    int i_end = mid;
    int j_start = mid + 1;
    int j_end = end;
    while (i_start <= i_end && j_start <= j_end)
    {
        if (arr[i_start] < arr[j_start])
        {
            temp[length] = arr[i_start];
            length++;
            i_start++;
        }
        else
        {
            temp[length] = arr[j_start];
            length++;
            j_start++;
        }
    }
    while (i_start <= i_end) // 把剩下数的合并
    {
        temp[length] = arr[i_start];
        i_start++;
        length++;
    }
    while (j_start <= j_end)
    {
        temp[length] = arr[j_start];
        length++;
        j_start++;
    }
    // 把辅助空间的数据放到原空间
    for (int i = 0; i < length; i++)
    {
        arr[start + i] = temp[i];
    }
}

/*基数排序*/
// void sort3(int *a, int n)
// {
//     int m = max(a, n);
//     int loop = figure(m);
//     int i;

//     for (i = 1; i <= loop; i++)
//     {
//         sort2(a, n, i);
//     }
// }

int main(void)
{
    int arr[ARR_LEN] = {3, 5, 1, -7, 4, 9, -6, 8, 10, 4};
    int len = 10;
    // int len = sizeof(arr) / sizeof(arr[0]); 获取数据长度
    int i;

    // 这里直接更换为其他排序方法即可
    BubbleSort(arr, len);

    for (i = 0; i < len; i++)
        printf("%d\t", arr[i]);
    putchar('\n');

    return 0;
}
