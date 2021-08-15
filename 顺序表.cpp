#include "linear_list.h"

template <class T>
class arrList : public List<T> //顺序表，向量
{
private:          //线性表的取值类型和取值空间
    T *aList;     //存储顺序表的实例
    int maxSize;  //顺序表实例的最大长度
    int curLen;   //顺序表实例的当前长度
    int position; //当前处理位置

public:
    arrList(const int size) //创建新表，设置表实例的最大长度
    {
        maxSize = size;
        aList = new T[maxSize];
        curLen = position = 0;
    }

    void clear();                              //置空线性表
    bool isEmpty();                            //线性表为空时，返回true
    bool append(const T value);                //在表位添加一个元素value，表的长度增1
    bool insert(const int p, const T value);   //在位置p上插入一个元素value，表的长度增1
    bool delete_element(const int p);          //删除位置p上的元素，表的长度减1
    bool getPos(int &p, const T value);        //查找值为value的元素并返回其位置p
    bool getValue(const int p, T &value);      //把位置p的元素返回到变量value
    bool setValue(const int p, const T value); //用value修改位置p的元素值

    ~arrList() //析构函数
    {
        delete[] aList;
    }
};

template <class T>
void arrList<T>::clear()
{
    delete[] aList;
    curLen = position = 0;
    aList = new T[maxSize];
}

template <class T>
bool arrList<T>::insert(const int p, const T value)
{
    int i;
    if(curLen >= maxSize)   //检查顺序表是否溢出，等于的话也无法插入，因为插入后长度就会大于maxSize
    {
        cout << "This list is overflow\n" << endl;
        return false;
    }

    if(p < 0 || p > curLen) //检查插入位置是否合法
    {
        cout << "Insertion point is illegal\n" << endl;
        return false;
    }

    for(i = curLen; i > p; i--)
        aList[i] = aList[i-1];  //将p~curLen-1的元素移动到p+1~curLen位置，p=curLen时不移动，右移

    aList[p] = value;   //位置p处插入新元素
    curLen++;   //表实际长度增1

    return true;
}

template <class T>
bool arrList<T>::delete_element(const int p)
{
    int i;
    if(curLen <= 0)   //检查顺序表是否为空
    {
        cout << "No element to delete\n" << endl;
        return false;
    }

    if(p < 0 || p > curLen-1) //检查删除位置是否合法
    {
        cout << "deletion is illegal\n" << endl;
        return false;
    }

    for(i = p; i < curLen-1; i++)
        aList[i] = aList[i+1];  //将p+1~curLen-1的元素移动到p~curLen-2位置

    curLen--;   //表实际长度减 1

    return true;
}

int main()
{
    arrList<int> test(5);
    cout << "test" << endl;
    return 0;
}