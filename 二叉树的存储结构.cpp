#include <stack>
#include "binaryTree.h"

//非递归方法查找父节点
template <class T>
BinaryTreeNode<T>* BinaryTree<T>::Parent(BinaryTreeNode<T> *current)
{
    stack<BinaryTreeNode<T> *> aStack;
    BinaryTreeNode<T> *pointer = root;

    aStack.push(NULL);  //栈底监视哨

    while(pointer)  //或者!aStack.empty()
    {
        if(current == pointer->leftchild() || current == pointer->rightchild())
            return pointer;  //如果point的左或右孩子是current，则返回parent

        if(pointer->rightchild() != NULL)   //非空右孩子入栈
            aStack.push(pointer->rightchild());
        if(pointer->leftchild() != NULL)
            pointer = pointer->leftchild(); //左路下降
        else    //左子树访问完毕，转向访问右子树
        {
            pointer = aStack.top();
            aStack.pop();   //获取栈顶元素并退栈
        }
    }
}

//递归方法查找父节点
template <class T>
BinaryTreeNode<T>* BinaryTree<T>::Parent(BinaryTreeNode<T> *rt, BinaryTreeNode<T> *current)
{
    //rt为子根
    BinaryTreeNode<T> *tmp;

    if(rt == NULL)
        return NULL;

    if(current == rt->leftchild() || current == rt->rightchild())
        return rt;  //如果子根的左或右孩子是current，则返回子根parent 

    if((tmp = Parent(rt->leftchild(), current)) != NULL)    //递归查找子根的左子树
        return tmp;

    if((tmp = Parent(rt->rightchild(), current)) != NULL)   //递归查找子根的右子树
        return tmp;

    return NULL;
}