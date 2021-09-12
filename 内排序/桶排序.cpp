#include <iostream>

using namespace std;

template <class Record>
void BucketSort(Record Array[], int n, int max)
{
    Record *TempArray = new Record[n];  //临时数组
    int *count = new int[max];  //桶容量计数器
    int i;

    for(i = 0; i < n; i++)  //把序列复制到临时数组
        TempArray[i] = Array[i];

    for(i = 0; i < max; i++)    //所有计数器初始都为0
        count[i] = 0;

    for(i = 0; i < n; i++)      //统计每个取值出现的次数
        count[Array[i]]++;

    for(i = 1; i < max; i++)    //统计小于等于i的元素个数
        count[i] = count[i-1]+count[i];     //c[i]记录i+1的起址

    for(i = n-1; i >= 0; i--)   //尾部开始，保证稳定性
        Array[--count[TempArray[i]]] = TempArray[i]; 
}