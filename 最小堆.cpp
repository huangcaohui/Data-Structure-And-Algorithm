#include <iostream>

using namespace std;

template <class T>
class MinHeap   //最小堆ADT定义
{
private:
    T *heapArray;   //存放堆数据的数组
    int CurrentSize;    //当前堆中元素数目
    int MaxSize;    //堆所能容纳的最大元素数目
    void BuildHeap();   //建堆

public:
    MinHeap(const int n);   //构造函数，n为最大元素数目
    virtual ~MinHeap(){delete []heapArray;} //析构函数
    bool isLeaf(int pos) const;     //如果是叶结点，返回TRUE
    int leftchild(int pos) const;   //返回左孩子位置
    int rightchild(int pos) const;   //返回右孩子位置
    int parent(int pos) const;  //返回父节点位置
    bool Remove(int pos, T &node);  //删除给定下标的元素
    bool Insert(const T &newNode);  //向堆中插入新元素
    T &RemoveMin();     //从堆顶删除最小值
    void SiftUp(int position);  //从position向上开始调整，使序列成为堆
    void SiftDown(int left);  //筛选法函数，参数left表示开始处理的数组下标
};

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

