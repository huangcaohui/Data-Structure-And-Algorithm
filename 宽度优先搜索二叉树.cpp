#include <queue>
#include "binaryTree.h"

template <class T> 
void BinaryTree<T>::LevelOrder(BinaryTreeNode<T> *root)
{
    queue<BinaryTreeNode<T> *> aQueue;
    BinaryTreeNode<T> *pointer = root;  //保存输入参数

    if(pointer)
        aQueue.push(pointer);   //根节点入队列

    while(!aQueue.empty())  //队列非空
    {
        pointer = aQueue.front();   //取队列首结点
        aQueue.pop();   //当前结点出队列
        Visit(pointer->value());    //访问当前结点

        if(pointer->leftchild())
            aQueue.push(pointer->leftchild());  //左子树进队列
        if(pointer->rightchild())
            aQueue.push(pointer->rightchild()); //右子树进队列
    }
}