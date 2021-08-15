#include "queue.h"
#include "link.h"

template <class T>
class lnkQueue : public Queue<T>
{
private:
    int size;   //队列中当前元素的个数
    Link<T> *front; //表示队头的指针
    Link<T> *rear;  //表示队尾的指针

public:
    lnkQueue(int size); //创建队列的实例
    ~lnkQueue();        //消除该实例，并释放其空间

    bool enQueue(const T item)  //item入队，插入队尾
    {
        if(rear == NULL)    //空队列
        {
            front = rear = new Link<T>(item, NULL); //空队的话，插入的元素既是队首，也是队尾 
        }
        else
        {
            rear->next = new Link<T>(item, NULL);
            rear = rear->next;        
        }
        size++;
        return true;
    }

    bool deQueue(T* item)   //返回队头元素并从队列中删除
    {
        Link<T> *tmp;

        if(size == 0)   //队列为空，没有元素可出队
        {
            cout << "队列为空" << endl;
            return false;
        }

        *item = front->data;
        tmp = front;    //队首元素
        front = front->next;    //队首指向下一位
        delete tmp; //删除队首

        if(front == NULL)
            rear = NULL;
        
        size--;
        return true;
    }
};