#include <iostream>

using namespace std;

template <size_t N>
class mySet
{
public:
    mySet();    //构造函数
    mySet(ulong X);     
    mySet<N>& set();   //设置元素属性
    mySet<N>& set(size_t P, bool X = true);
    mySet<N>& reset(); //把集合设置为空
    mySet<N>& reset(size_t P); //删除元素P
    bool at(size_t P) const;    //属于运算
    size_t count() const;   //集合中元素个数
    bool none() const;      //判断是否空集
};