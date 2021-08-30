#include "tree.h"
#include <queue>

template<class T>
void Tree<T>::RootFirstTraverse(TreeNode<T> *root)
{
    while(root != NULL)
    {
        Visit(root->Value());   //访问当前结点
        RootFirstTraverse(root->LeftMostChild());
        root = root->RightSibling();    //遍历其他树
    }
}

//广度优先遍历森林
template<class T>
void Tree<T>::WidthTraverse(TreeNode<T> *root)
{
    queue<TreeNode<T>*> aQueue;
    TreeNode<T> *pointer = root;

    while (pointer != NULL)
    {
        aQueue.push(pointer);
        pointer = pointer->RightSibling; //pointer指向右兄弟
    }
    
    while(!aQueue.empty())
    {
        pointer = aQueue.front();   //获得队首元素
        aQueue.pop();   //当前结点出队列
        Visit(pointer->Value());    //访问当前结点
        pointer = pointer->LeftSibling();   //pointer指向最左孩子

        while(pointer != NULL)
        {
            aQueue.push(pointer);
            pointer = pointer->RightSibling();
        }
    }
}

template<class T>
TreeNode<T> *Tree<T>::Parent(TreeNode<T> *current)
{
    queue<TreeNode<T>*> aQueue;
    TreeNode<T> *upperlevelpointer;
    TreeNode<T> *pointer = root;
    TreeNode<T> *father = upperlevelpointer = NULL; //记录父结点

    if(current != NULL && pointer != current)
    {
        while(pointer != NULL)  //森林中所有根节点进队列
        {
            if(current == pointer)
                break;
            aQueue.push(pointer);   //当前结点进队列
            pointer = pointer->RightSibling();  //指针指向右
        }
    }

    while(!aQueue.empty())
    {
        pointer = aQueue.front();   //取队列首结点指针
        aQueue.pop();   //当前元素出队列
        upperlevelpointer = pointer;    //指向上一层结点
        pointer = pointer->LeftMostChild(); //指向最左孩子

        while(pointer)
        {
            if(current == pointer)
            {
                father = upperlevelpointer; //返回父
                break;
            }
            else
            {
                aQueue.push(pointer);
                pointer = pointer->RightSibling();
            }
        }
    }

    aQueue.clear();     //清空队列
    return father;
}

template<class T>
void Tree<T>::DestroyNodes(TreeNode<T> *root)
{
    if(root)
    {
        DestroyNodes(root->LeftMostChild());  //递归删除第一颗子树
        DestroyNodes(root->RightSibling());  //递归删除其他子树
        delete root;    //删除第一棵树的根结点
    }
}