#include <iostream>

using namespace std;

template <class T>
class Queue
{
public: //队列的运算级
    void clear();   //队列的运算集
    bool enQueue(const T item); //将item插入队尾，成功返回真，否则返回假
    bool deQueue(T &item);  //返回队头元素并将其从队列中删除，成功则返回真
    bool getFront(T &item); //返回队头元素，但不删除，成功则返回真
    bool isEmpty(); //返回真，若队列已空
    bool isFull();  //返回真，若队列已满
};