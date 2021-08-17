#include "minHeap.h"

template <class T>
class HuffmanTree
{
private:
    HuffmanTreeNode<T> *root;   //Huffman树的树根
    void MergeTree(HuffmanTreeNode<T> &ht1, HuffmanTreeNode<T> &ht2,
                 HuffmanTreeNode<T> *parent);   //把ht1和ht2为根的合并成一棵以parent为根的Huffman子树

public:
    HuffmanTree(T weight[], int n); //构造Huffman树，weight树存储权值的数组，n是数组长度
    virtual ~HuffmanTree(){DeleteTree(root);}   //析构函数
};

template<class T>
HuffmanTree<T>::HuffmanTree(T weight[], int n)
{
    MinHeap<HuffmanTreeNode<T>> heap;   //定义最小堆
    HuffmanTreeNode<T> *parent, &leftchild, &rightchild;
    HuffmanTreeNode<T> *NodeList = new HuffmanTreeNode<T>[n];

    for(int i = 0; i<n; i++)
    {
        NodeList[i].element = weight[i];
        NodeList[i].parent = NodeList[i].left = NodeList[i].right = NULL;
        heap.Insert(NodeList[i]);   //向堆中添加元素
    }

    for(i=0; i<n-1; i++)    //通过n-1次合并建立Huffman树
    {
        parent = new HuffmanTreeNode<T>;
        firstchild = heap.RemoveMin();   //选值最小的结点
        secondchild = heap.RemoveMin(); //选取次小的结点
        MergeTree(firstchild, secondchild, parent); //合并权值最小的两树
        heap.Insert(*parent);   //把parent插入到堆中
        root = parent;  //建立根节点
    }
    delete []NodeList;
}