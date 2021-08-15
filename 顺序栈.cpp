#include "stack.h"

template <class T>
class arrStack : public Stack<T>
{
private:            //栈的顺序存储
    int mSize;      //栈中最多可存放的元素个数
    int top;        //栈顶位置，应小于mSize
    T *st;         //存放栈元素的数组

public:             //栈的运算的顺序实现
    arrStack(int size)  //创建一个给定长度的顺序栈实例
    {
        mSize = size;
        top = -1;
        st = new T[mSize];
    }

    arrStack()      //创建一个顺序栈的实例
    {
        top = -1;
    }

    ~arrStack()
    {
        delete []st;
    }

    void clear()    //清空栈
    {
        top = -1;
    }

    bool push(const T item);    //item入栈，成功返回正，否则假
    bool pop(T &item);  //返回栈顶内容并弹出，成功返回真，否则返回假
    bool top_element(T &item);  //返回栈顶但不弹出，成功返回真，否则假
    bool isEmpty();     //若栈已空返回真
    bool isFull();      //若栈已满返回真
};

template <class T>
bool arrStack<T>::push(const T item)
{
    if(top == mSize-1)  //栈已满
    {
        cout << "栈满溢出" << endl;
        return false;
    }
    else    //新元素入栈并修改栈顶指针
    {
        st[++top] = item;
        return true;
    }
}

template <class T>
bool arrStack<T>::pop(T &item)  //出栈
{
    if(top == -1)   //栈为空
    {
        cout << "栈为空，不能执行出栈操作" << endl;
        return false;
    }
    else
    {
        item = st[top--];
        return true;
    }
}

int main()
{
    cout << "test" << endl;
    return 0;
}