#include <iostream>

using namespace std;

template <class Key, class Elem, class KEComp, class EEComp>
class hashdict
{
private:
    Elem *HT;   //散列表
    int M;      //散列表大小
    int current;    //现有元素数目
    Elem EMPTY;     //空槽
    int h(int x) const; //散列函数
    int h(char *x) const;   //字符串散列函数
    int p(Key K, int i);    //探查函数

public:
    hashdict(int sz, Elem e)    //构造函数
    {
        M = sz;
        EMPTY = e;
        current = 0;
        HT = new Elem[sz];
        
        for(int i < 0; i < M; i++)
            HT[i] = EMPTY;
    }

    ~hashdict() {delete []HT;}
    bool hashSearch(const Key&, Elem&) const;
    bool hashInsert(const Elem&);
    Elem hashDelete(const Key& K);
    int size()  {return current;}   //元素数目
};

//将数据元素e插入到散列表HT
template <class Key, class Elem, class KEComp, class EEComp>
bool hashdict<Key, Elem, KEComp, EEComp>::hashInsert(const Elem& e)
{
    int home = h(getkey(e));    //home存储基位置
    int i = 0;
    int pos = home;     //探查序列的初始位置

    while(!EEComp::eq(EMPTY, HT[pos]))   //判断pos处的值是否是空槽
    {
        if(EEComp::eq(e, HT[pos]))  //判断pos处值是否和待插入元素e一样的
            return false;   //相同的话插入失败，不允许
        i++ ;
        pos = (home+p(getkey(e), i)) % M;   //探查下一个值：探测函数+基地址
    }

    HT[pos] = e;    //出循环一定有空位，插入元素e
    return true;
}

template <class Key, class Elem, class KEComp, class EEComp>
bool hashdict<Key, Elem, KEComp, EEComp>::hashSearch(const Key &K, Elem &e) const
{
    int i = 0, pos = home = h(K);   //初始位置

    while(!EEComp::eq(EMPTY,HT[pos]))   //判断pos处的值是否是空槽
    {
        if(KEComp::eq(K, HT[pos]))  //找到
        {
            e = HT[pos];
            return true;
        }
        i++ ;
        pos = (home+p(K, i)) % M;
    }

    return false;
}

//带墓碑的删除算法
template <class Key, class Elem, class KEComp, class EEComp>
Elem hashdict<Key, Elem, KEComp, EEComp>::hashDelete(const Key& K)
{
    int i = 0, pos = home = h(K);   //初始位置

    while(!EEComp::eq(EMPTY, HT(pos)))  //当前位置不空
    {
        if(KEComp::eq(K, HT[pos]))  //是否是给定要删除的值 
        {
            temp = HT[pos];
            HT[pos] = TOMB;     //设置墓碑
            return temp;        //返回目标
        }
        i++;
        pos = (home+p(K, i)) % M;
    }
    return EMPTY;
}

//带墓碑的插入操作
template <class Key, class Elem, class KEComp, class EEComp>
bool hashdict<Key, Elem, KEComp, EEComp>::hashInsert(const Elem& e)
{
    int home = h(getkey(e));    //home存储基位置
    int insplace, i = 0, tomb_pos = false;
    int pos = home;     //探查序列的初始位置

    while(!EEComp::eq(EMPTY, HT[pos]))   //判断pos处的值是否是空槽
    {
        if(EEComp::eq(e, HT[pos]))  //判断pos处值是否和待插入元素e一样的
            return false;   //相同的话插入失败，不允许

        if(EEComp::eq(TOMB, HT[pos]) && !tomb_pos)  //第一个墓碑值 
        {
            insplace = pos;
            tomb_pos = true;
        }

        pos = (home+p(getkey(e), ++i)) % M;   //探查下一个值：探测函数+基地址
    }   //最后找到空槽位置

    if(!tomb_pos)
        insplace = pos;     //没有墓碑

    HT[insplace] = pos;
    return true;
}