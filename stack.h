#include <iostream>

using namespace std;

template <class T>
class Stack
{
public:
    void clear();   //变为空栈
    bool push(const T item);    //item入栈，成功返回正，否则假
    bool pop(T &item);  //返回栈顶内容并弹出，成功返回真，否则返回假
    bool top(T &item);  //返回栈顶但不弹出，成功返回真，否则假
    bool isEmpty();     //若栈已空返回真
    bool isFull();      //若栈已满返回真
};