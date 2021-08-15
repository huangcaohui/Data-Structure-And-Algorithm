#include <iostream>

using namespace std;

template <class T>
class Link
{
public:
    T data; //用于保存结点元素的内容
    Link<T> *next;  //指向后继结点的指针

    Link(const T info, const Link<T> *nextValue = NULL)
    {
        data = info;
        next = nextValue;
    }

    Link(const Link<T> *nextValue)
    {
        next = nextValue;
    }
};