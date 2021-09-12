#include <iostream>

using namespace std;

template <class Record>
void sort(Record Array[], int n)
{
    int i;

    //建堆
    MaxHeap<Record> max_heap = MaxHeap<Record>(Array, n, n);

    //算啊操作n-1次，最小元素不需要出堆
    for(i = 0; i < n-1; i++)
        //依次找出剩余记录中的最大记录，即堆顶
        max_heap.RemoveMax(); 
}