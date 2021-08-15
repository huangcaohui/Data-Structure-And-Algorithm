#include "linear_list.h"
#include "link.h"

template <class T>
class lnkList : public List<T>
{
private:
    Link<T> *head, *tail;  //单链表的头、尾指针
    Link<T> *setPos(const int p);   //查找第p个元素指针

public:
    lnkList(int s);                            //构造函数
    ~lnkList();                                //析构函数
    void clear();                              //置空链表
    int length();                              //返回此链表当前实际长度
    bool isEmpty();                            //链表为空时，返回true
    bool append(const T value);                //在表位添加一个元素value，表的长度增1
    bool insert(const int p, const T value);   //在位置p上插入一个元素value，表的长度增1
    bool delete_element(const int p);          //删除位置p上的元素，表的长度减1
    bool getPos(int &p, const T value);        //查找值为value的元素并返回其位置p
    bool getValue(const int p, T &value);      //把位置p的元素返回到变量value
};

template <class T>
Link<T> *lnkList<T>::setPos(int i)
{
    int count = 0;

    if(i == -1) //i为-1则定位到头结点
        return head;
    
    //循环定位，若i为0则定位到第一个结点
    Link<T> *p = head->next;    
    while(p != NULL && count < i)   //当链表中结点数小于i时返回NULL（Link初始化时默认为NULL）
    {
       p = p->next;
       count++;
    }

    return p;
}

template <class T>
bool lnkList<T>::insert(const int i, const T value)
{
    Link<T> *p, *q;

    if((p=setPos(i-1)) == NULL) //p是第i个结点的前驱
    {
        cout << "非法插入点" << endl;
        return false;
    }

    q = new Link<T>(value, p->next);
    p->next = q;

    if(p == tail)   //插入点在链尾，插入节点成为新的链尾
        tail = q;

    return true;
}

template <class T>
bool lnkList<T>::delete_element(const int i)
{
    Link<T> *p, *q;

    //待删除的结点不存在，即给定的i大于当前链中元素个数
    if((p = setPos(i-1)) == NULL || p == tail)  //p为待删除点的前驱 
    {
        cout << "非法插入点" << endl;
        return false;
    }

    q = p->next;    //q是真正待删除点
    if(q == tail)   //待删除结点为尾结点，则修改尾指针
    {
        tail = p;
        p->next = NULL; //最后一个结点的指向要为NULL 
    }
    else            //删除结点q并修改链指针
    {
        p->next = q->next;
    }
    delete q;
    return true;
}

int main()
{
    cout << "test" << endl;
    return 0;
}