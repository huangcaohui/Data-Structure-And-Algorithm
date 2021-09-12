#include <iostream>

using namespace std;

template <class Record>
void BubbleSort(Record Array[], int n)
{
    bool NoSwap;    //是否发生了交换的标志
    int i, j;

    for(i = 0; i < n-1; i++)
    {
        if(Array[j] > Array[j-1])   //判断是否逆置
        {
            swap(Array, j, j-1);    //交换逆置对
            NoSwap = false;     //发生了交换，标志变为假
        }

        if(NoSwap)  //没发生交换，则已经完成排好序
            return;
    }
}