#include <iostream>

using namespace std;

template <class Record>
void MergeSort(Record Array[], Record TempArray[], int left, int right)
{
    //Array为待排序数组，left，right两端
    int middle;

    if(left < right)    //序列中只有0或1个记录，不用排序
    {
        middle = (left+right)/2;    //平均为两个子序列
        //对左边一半进行递归
        MergeSort(Array, TempArray, left, middle);
        //对右边一半进行递归
        MergeSort(Array, TempArray, middle+1, right);
        Merge(Array, TempArray, left, right, middle);   //归并
    }
}

template <class Record>
void Merge(Record Array[], Record TempArray[], int left, int right, int middle)
{
    int i, j, index1, index2;
    //将数组暂存入临时数组
    for(j = left; j <= right; j++)
        TempArray[j] = Array[j];

    index1 = left;  //左边子序列的起始位置
    index2 = middle+1;  //右边子序列的起始位置
    i = left;       //从左开始归并

    while(index1 <= middle && index2 <= right)
    {
        //取较小者插入合并数组中
        if(TempArray[index1] <= TempArray[index2])  //相等的时候选择左序列，保证算法稳定性
            Array[i++] = TempArray[index1++];
        else
            Array[i++] = TempArray[index2++];
    }

    while(index1 <= middle) //只剩左序列，可以直接复制
        Array[i++] = TempArray[index1++];

    while(index2 <= right)  //与上个循环互斥，复制右序列
        Array[i++] = TempArray[index2++]; 
}

int THRESHOLD = 28;

//优化的排序算法，Sedgewick算法
template <class Record>
void ModMergeSort(Record Array[], Record TempArray[], int left, int right)  //Array为待排序数组，left，roght两端
{
    int middle;
    
    if(right-left+1 > THRESHOLD)    //长序列递归
    {
        middle = (left+right)/2;    //从中间划分两个子序列
        ModMergeSort(Array, TempArray, left, middle);  //左
        ModMergeSort(Array, TempArray, middle+1, right);    //右

        //对相邻的有序序列进行归并
        ModMerge(Array, TempArray, left, right, middle);
    }
    else
        InsertSort(&Array[left], right-left+1);  //小序列插入排序 
}

template <class Record> 
void ModMerge(Record Array[], Record TempArray[], int left, int right, int middle)
{
    int inndex1, index2;    //两个子序列的起始位置
    int i,j,k;

    for(i = left; i <= middle; i++)
        TempArray[i] = Array[i];    //复制左边的子序列

    for(j = 1; j < right-middle; j++)   //颠倒复制右序列
        TempArray[right-j+1] = Array[j+middle];

    for(index1 = left, index2 = right, k = left; k <= right; k++)
        if(TempArray[index1] <= TempArray[index2])
            Array[k] = TempArray[index1++];
        else
            Array[k] = TempArray[index2--];   
}