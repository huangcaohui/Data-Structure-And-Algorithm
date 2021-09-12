#include <iostream>

using namespace std;

template <class Record>
void SelectSort(Record Array[], int n)
{
    //依次选出第i小的记录，即剩余记录中最小的那个
    for(int i = 0; i < n-1; i++)
        //首先假设记录i就是最小的
        int Smallest = i;
        //开始向后扫描所有剩余记录
        for(int j = i+1; j < n; j++)
            //如果发现更小的记录，记录它的位置
            if(Array[j] < Array[Smallest])
                Smallest = j;
        //将第i小的记录放在数组中的第i个位置
        swap(Array, i, Smallest);
}