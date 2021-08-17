#include "minHeap.h"

template <class T>
void MinHeap<T>::SiftDown(int position)
{
    int i = position;   //标识父节点
    int j = 2*i+1;      //标识关键值较小的子结点
    T temp = heapArray[i];  //保存父节点 

    while(j < CurrentSize)  //子结点值比父节点都大时停止 
    {
        if((j < CurrentSize-1) && (heapArray[j]>heapArray[j+1]))
            j++;    //j指向数值较小的子结点
        
        if(temp > heapArray[j])
        {
            heapArray[i] = heapArray[j];    //子结点值替换父节点值
            i = j;
            j = 2*j + 1;    //向下继续
        }
        else
            break;
    }

    heapArray[i] = temp;    //i为找到的最终子结点位置，用初始父节点值替换子结点值 
}

template <class T>
void MinHeap<T>::SiftUp(int position)
{
    //从position向上开始调整，使序列成为堆
    int temppos = position;

    //不是父子结点直接swap
    T temp = heapArray[temppos];
    while((temppos>0) && (heapArray[parent(temppos)]>temp))
    {
        heapArray[temppos] = heapArray[parent(temppos)];
    }
    heapArray[temppos] = temp;  //找到最终位置
}

//建最小堆，从第一个分支结点heapArray[CurrentSize/2-1]开始，自底向上逐步把以子树调整成堆
template<class T>
void MinHeap<T>::BuildHeap()
{
    //反复调用筛选函数
    for(int i = CurrentSize/2-1; i>=0; i--)
    {
        SiftDown(i);
    }
}

template<class T>
bool MinHeap<T>::Insert(const T&newNode)
{
    //向堆中插入新元素newNode
    if(CurrentSize == MaxSize)  //堆空间已装满
        return false;
    
    heapArray[CurrentSize] = newNode;
    SiftUp(CurrentSize);    //向上调整
    CurrentSize++;
}

//删除操作拿最后一个元素取替换待删除元素  
template<class T>
bool MinHeap<T>::Remove(int pos, T &node)
{
    if((pos)<0 || (pos>=CurrentSize))
        return false;

    T temp = heapArray[pos];
    heapArray[pos] = heapArray[--CurrentSize];

    if(heapArray[parent(pos)] > heapArray[pos])
        SiftUp(pos);    //上升筛
    else
        SiftDown(pos);  //向下筛

    node = temp;
    return true;
}