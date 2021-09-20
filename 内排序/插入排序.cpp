#include <iostream>

using namespace std;

template <class Record>
void ImprovedInsertSort(Record Array[], int n)  //Array[]为待排序数组，n为数组长度
{
    Record TempRecord;  //临时变量

    for(int i = 0; i < n; i++)  //依次插入第i个记录
    {
        TempRecord = Array[i];

        //从i开始往前寻找记录i的正确位置
        int j = i-1;

        //将那些大于等于记录i的记录后移
        while(j > 0 && TempRecord < Array[j])
        {   
            Array[j+1] = Array[j];
            j = j - 1;
        }

        //此事j后面就是记录i的正确位置，回填
        Array[j+1] = TempRecord;
    }
}