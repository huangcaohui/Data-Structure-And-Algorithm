#include <iostream>

using namespace std;

template <class T>
class List
{
    void clear();   //置空线性表
    bool isEmpty(); //线性表为空时，返回true
    bool append(const T value); //在表位添加一个元素value，表的长度增1
    bool insert(const int p, const T value);    //在位置p上插入一个元素value，表的长度增1
    bool delete_element(const int p);   //删除位置p上的元素，表的长度减1
    bool getPos(int &p, const T value);   //查找值为value的元素并返回其位置p
    bool getValue(const int p, T &value);   //把位置p的元素返回到变量value
    bool setValue(const int p, const T value);   //用value修改位置p的元素值
};