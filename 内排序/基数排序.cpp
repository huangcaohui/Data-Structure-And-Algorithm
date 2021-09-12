#include <iostream>

using namespace std;

template <class Record>
void RadixSort(Record Array[], int n, int d, int r)
{
    Record *TempArray = new Record[n];
    int *count = new int[r];
    int i,j,k;
    int Radix = 1;  //模进位，用于取Array[i]的第i位

    for(i = 1; i <= d; i++)     //对第i个排序码分配
    {        
        for(j = 0; j < r; j++)
            count[j] = 0;   //初始计数器均为0

        for(j = 0; j < n; j++)  //统计每桶记录数
        {
            k = (Array[j]/Radix) % r;     //取第i位
            count[k]++;
        }

        for(j = 1; j < r; j++)  //给桶划分下标界
            count[j] = count[j-1] + count[i];

        for(j = n-1; j >= 0; j--)   //从数组尾部收集
        {
            k = (Array[j]/Radix) % r;   //取第i位
            count[k]--;     //桶剩余量计数器减1
            TempArray[count[k]] = Array[j];     //入桶
        }

        for(j = 0; j < n; j++)      //内容复制回Array中
            Array[j] = TempArray[j];

        Radix *= r;     //修改模Radix
    }
}