#include <iostream>

using namespace std;

class Node  //结点类
{
public:
    int key;    //结点的关键码值
    int next;   //下一个结点在数组中的下标
};

class StaticQueue   //静态队列类
{
public:
    int head;
    int tail;
};

template <class Record>
void RadixSort(Record *Array, int n, int d, int r)
{
    int i, first = 0;   //first指向第一个记录
    StaticQueue *queue  = new StaticQueue[r];

    for(i = 0; i < n-1; i++)
        Array[i].next = i+1;    //初始化静态指针域

    Array[n-1].next = -1;       //链尾next为空，类似于None 

    //对第i个排序码进行分配和收集，一个d趟
    for(i = 0; i < d; i++)
    {
        Distribute(Array, first, i, r, queue);
        Collect(Array, first, r, queue);
    }

    delete[] queue;
    AddrSort(Array, n, first);  //整理后，按下标有序
}

template <class Record>
void Distribute(Record *Array, int first, int i, int r, StaticQueue *queue)
{
    int j, k, a, curr = first;

    for(j = 0; j < r; j++)
        queue[j].head = -1;     //空桶

    while(curr != -1)   //对整个静态链进行分配
    {
        k = Array[curr].key;

        for(a = 0; a < i; a++)  //取第i位排序码数字k
            k = k/r;
        
        k = k%r;

        if(queue[k].head == -1)     //把数据分配到第k个桶中
            queue[k].head = curr;
        else
            array[queue[k].tail].next = curr;

        queue[k].tail = curr;
        curr = Array[curr].next;    //curr移动，继续分配
    }
}

template <class Record>
void Collect(Record *Array, int &first, int r, StaticQueue *queue)
{
    int last, k = 0;        //已收集到的最后一个记录

    while(queue[k].head == -1)      //找到第一个非空队
        k++;

    first = queue[k].head;
    last = queue[k].tail;

    while(k < r-1)      //继续收集下一个非空队列
    {
        k++;
        while(k < r-1 && queue[k].head == -1)
            k++;

        if(queue[k].head != -1) //试探下一个队列
        {
            Array[last].next = queue[k].head;
            last = queue[k].tail;       //最后一个为序列的尾部
        }
    }
    Array[last].next = -1;      //收集完毕
}