#include <iostream>

using namespace std;

template <class Record>
void ShellSort(Record Array[], int n)
{
    //shell排序，Array[]为待排序数组，n为数组长度
    int i, delta;

    //增量delta每次除以2递减
    for(delta = n/2; delta > 0; delta /=2)
        for(i = 0; i < delta; i++)
            //分别对delta个子序列进行插入排序，delta为步长
            //“&”船Array[i]的地址，数组总长度为n-i 
            ModInsSort(&Array[i], n-i, delta);

    //如果增量序列不能保证最后一个delta间距为1，可以安排下面这个扫尾性质的插入排序
    //ModInsSort(Array, n, 1);
}

template <class Record>
void ModInsSort(Record Array[], int n, int delta)
{
    int i,j;

    //对子序列中第i个记录，寻找合适的位置插入
    for(j = i; j >= delta; j -= delta)
    {
        if(Array[j] < Array[j-delta])   //逆置对
            swap(Array, j, j-delta);    //交换
        else
            break;
    }
}