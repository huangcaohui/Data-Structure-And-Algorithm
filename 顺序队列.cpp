#include "queue.h"

template <class T>
class arrQueue : public Queue<T>
{
private:
    int mSize;  //存放队列的数组的大小
    int front;  //表示队头所在位置的下标
    int rear;   //表示队尾所在位置的下标
    T * qu;     //存放类型为T的队列元素的数组

public:
    arrQueue(int size); //创建队列的实例
    ~arrQueue();    //消除该实例，并释放其空间
};

template <class Elem>
class Aqueue : public Queue<Elem>
{
private:
    int size;  //存放队列的数组的大小
    int front;  //表示队头所在位置的下标
    int rear;   //表示队尾所在位置的下标
    Elem * listArray;     //存放队列元素的数组

public:
    Aqueue(int sz)
    {
        //让存储元素的数组多预留一个空位
        size = sz + 1;  //size数组长，sz队列最大长度
        rear = 0; front = 1;    //也可以rear=-1；front=0
        listArray = new Elem[size];
    }
    ~Aqueue()    //消除该实例，并释放其空间
    {
        delete []listArray;
    }

    void clear()
    {
        front = rear + 1;
    }

    bool enqueue(const Elem &it)
    {
        if(((rear+2)%size) == front)
            return false;   //还剩一个空位，就要报满

        rear = (rear+1)%size;
        listArray[rear] = it;
        return true;
    }

    bool dequeue(Elem &it)
    {
        if(length() == 0)
            return false;   //队列为空

        it = listArray[front];  //先出队，在移动front下标
        front = (front+1)%size; //环形增加
        return true;
    }

    bool frontValue(Elem &it) const
    {
        if(length() == 0)
            return false;   //队列为空

        it = listArray[front];

        return true;   
    }

    int length() const
    {
        return (size+(rear-front+1))%size;
    }
};