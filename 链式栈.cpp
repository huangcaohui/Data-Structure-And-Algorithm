#include "stack.h"
#include "link.h"

template <class T>
class lnkStack : public Stack<T>
{
private:            //栈的链式存储
    Link<T> * top;      //指向栈顶的指针
    int size;           //存放元素的个数

public:             //栈的运算的顺序实现
    lnkStack(int defSize)  //构造函数
    {
        top = NULL;
        size = 0;
    }

    ~lnkStack()             //析构函数
    {
        clear();
    }

    void clear()    //清空栈
    {
        top = NULL;
        size = 0;
    }

    bool push(const T item);    //item入栈，成功返回正，否则假
    bool pop(T &item);  //返回栈顶内容并弹出，成功返回真，否则返回假
    bool top_element(T &item);  //返回栈顶但不弹出，成功返回真，否则假
    bool isEmpty();     //若栈已空返回真
    bool isFull();      //若栈已满返回真
};

template <class T>
bool lnkStack<T>::push(const T item)
{
    Link<T> *tmp = new Link<T>(item, top);  //data=item，next=top 
    top = tmp;  //数据压入栈中，最上方元素为栈顶top
    size++;
    return true;
};

template <class T>
bool lnkStack<T>::pop(T &item)
{
    Link<T> *tmp;

    if(size == 0)
    {
        cout << "栈为空，不能执行出栈操作" << endl;
        return false;
    }

    item = top->data;
    tmp = top->next;
    delete top;
    top = tmp;
    size--;

    return true;
}


int main()
{
    cout << "test" << endl;
    return 0;
}