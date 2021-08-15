#include <stack>
#include "binaryTree.h"

template <class T>
void BinaryTree<T>::PreOrderWithoutRecusion(BinaryTreeNode<T> *root)
{
    stack <BinaryTreeNode<T> *> aStack;
    BinaryTreeNode<T> *pointer = root;
    aStack.push(NULL);  //栈底监视哨，主要方便程序编写，用于while判断栈是否为空

    while(pointer)  //或者!aStack.empty()
    {
        Visit(pointer->value());    //访问当前结点
        
        if(pointer->rightchild() != NULL)   //右孩子入栈
            aStack.push(pointer->rightchild());

        if(pointer->leftchild() != NULL)   
            pointer = pointer->leftchild(); //左路下降
        else    //左子树访问完毕，转向访问右子树
        {
            pointer = aStack.top();
            aStack.pop();   //栈顶元素退栈
        }
    }
}

template <class T>
void BinaryTree<T>::InOrderWithoutRecusion(BinaryTreeNode<T> *root)
{
    stack <BinaryTreeNode<T> *> aStack;
    BinaryTreeNode<T> *pointer = root;
    aStack.push(NULL);  //栈底监视哨，主要方便程序编写，用于while判断栈是否为空

    while(!aStack.empty() || pointer)  //或者!aStack.empty()
    {
        if(pointer)
        {
            Visit(pointer->value());    //前序访问点
            aStack.push(pointer);   //当前结点地址入栈
            pointer = pointer->leftchild();   //当前链接结构指向左孩子
        }
        else    //左子树访问完毕，访问右子树
        {
            pointer = aStack.top();
            aStack.pop();   //栈顶元素退栈
            Visit(pointer->value());    //访问当前结点
            pointer = pointer->rightchild();    //当前链接结构指向右孩子
        }
    }
}

template <class T>
void BinaryTree<T>::PostOrderWithoutRecusion(BinaryTreeNode<T> *root)
{
    StackElement<T> element;
    stack <StackElement<T>> aStack;
    BinaryTreeNode<T> *pointer = root;

    while(!aStack.empty() || pointer)
    {
        while(pointer != NULL)  //沿非空指针压栈，并左路下降
        {
            element.pointer = pointer;
            element.tag = Left;
            aStack.push(element);   //把标志位为Left的结点压入栈
            pointer = pointer->leftchild();
        }
        element = aStack.top();
        aStack.pop();   //获得栈顶元素，并退栈
        pointer = element.pointer;

        if(element.tag == Left) //如果从左子树回来
        {
            element.tag = Right;
            aStack.push(element);   //置标志位为Right
            pointer = pointer->rightchild();
        }
        else
        {
            Visit(pointer->value());    //访问当前结点
            pointer = NULL;     //置point指针为空，以继续弹栈
        }
    }
}