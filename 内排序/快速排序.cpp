#include <iostream>

using namespace std;

template <class Record>
void QuickSort(Record Array[], int left, int right)
{
    //Array[]为待排序数组，left，right分别为数组两端
    if(right <= left)   //只有0或1个记录，就不需排序
        return;

    int pivot = SelectPivot(left, right);   //选择轴值
    swap(Array, pivot, right);  //轴值放到数组末端，最右边元素空出 
    pivot = Partition(Array, left, right);  //分割后轴值正确
    QuickSort(Array, left, pivot-1);    //左子序列递归快排
    QuickSort(Array, pivot+1, right);   //右子序列递归快排
}

template <class Record>
int Partition(Record Array[], int left, int right)
{
    //分割函数，分割后轴值已到达正确位置
    int l = left;       //l为左指针
    int r = right;      //r为右指针
    Record TempRecord = Array[r];   //保存轴值
    while(l != r)       //l,r不断向中间移动，直到相遇
    {
        //l指针向右移动，直到找到一个大于轴值的记录
        while(Array[l] <= TempRecord && r > l)
            l++;
        if(l < r)   //未相遇，将逆置元素换到右边空位
        {
            Array[r] = Array[l];
            r--;    //r指针向左移动一步
        }

        //r指针向左移动，直到找到一个小于轴值的记录
        while(Array[r] >= TempRecord && r > l)
            r--;
        if(l < r)   //未相遇，将逆置元素换到左边空位
        {
            Array[l] = Array[r];
            l++;    //l指针向右移动一步
        }
    }
    Array[l] = TempRecord;  //把轴值回填到分界位置l上
    return l;       //返回分界位置l
}

int SelectPivot(int left, int right)
{
    //选择轴值，参数left，right分别表示序列的左右端下标
    return (left+right)/2;      //选中间记录作为轴值
}