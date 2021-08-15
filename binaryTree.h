#include <iostream>

using namespace std;

template <class T> class BinaryTree;

template <class T>
class BinaryTreeNode
{
friend class BinaryTree<T>;  //申明二叉树为友元类

private:
    T info; //二叉树结点数据域

public:
    BinaryTreeNode();    //缺省构造函数
    BinaryTreeNode(const T &ele);    //给定数据的构造
    T value() const;    //返回当前结点数据
    BinaryTreeNode<T> *leftchild() const;    //返回左子树
    BinaryTreeNode<T> *rightchild() const;  //返回右子树
    BinaryTreeNode<T> *Parant(BinaryTreeNode<T> *rt, BinaryTreeNode<T> *current);   //寻找父节点
    void setLeftchild(BinaryTreeNode<T>*);  //设置左子树
    void setRightchild(BinaryTreeNode<T>*); //设置右子树
    void setValue(const T &val);    //设置数据域
    bool isLeaf()const;             //判断是否为叶节点
    BinaryTreeNode<T> & operator = (const BinaryTreeNode<T> & Node);    //重载赋值运算符
};

template <class T>
class BinaryTree
{
private:
    BinaryTreeNode<T> *root;    //二叉树根节点
    BinaryTreeNode<T> *left;    //指向左子树的指针
    BinaryTreeNode<T> *right;   //指向右子树的指针

public:
    BinaryTree()
    {
        root = NULL;    //构造函数
    }

    ~BinaryTree()
    {
        DeleteBinaryTree(root); //析构函数
    }

    bool isEmpty() const;   //判定二叉树是否为空树
    BinaryTreeNode<T> *Root() 
    {
        return root;    //返回根节点
    }

    BinaryTreeNode<T> *Parent(BinaryTreeNode<T> *current);  //非递归查找，返回父节点
    BinaryTreeNode<T> *Parent(BinaryTreeNode<T> *rt, BinaryTreeNode<T> *current);  //递归查找，返回父节点
    BinaryTreeNode<T> *LeftSibling(BinaryTreeNode<T> *current);  //返回左兄弟结点
    BinaryTreeNode<T> *RightSibling(BinaryTreeNode<T> *current);  //返回左兄弟结点
    void CreateTree(const T &info, BinaryTreeNode<T> &leftTree, BinaryTreeNode<T> &rightTree);  //构造新数
    void PreOrder(BinaryTreeNode<T> *root);  //前序遍历二叉树或其子树
    void PreOrderWithoutRecusion(BinaryTreeNode<T> *root);  //非递归前序遍历二叉树或其子树
    void InOrder(BinaryTreeNode<T> *root);  //中序遍历二叉树或其子树
    void InOrderWithoutRecusion(BinaryTreeNode<T> *root);  //非递归中序遍历二叉树或其子树
    void PostOrder(BinaryTreeNode<T> *root);  //后序遍历二叉树或其子树
    void PostOrderWithoutRecusion(BinaryTreeNode<T> *root);  //非递归中后序遍历二叉树或其子树
    void LevelOrder(BinaryTreeNode<T> *root); //按层次遍历（宽度优先索索）二叉树或其子树
    void DeleteBinaryTree(BinaryTreeNode<T> *root);  //删除二叉树或其子树
};

enum Tags {Left, Right};    //定义枚举类型标志位

template <class T>
class StackElement  //栈元素定义
{
public:
    BinaryTreeNode<T> *pointer; //指向二叉树结点的指针
    Tags tag;   //标志位
};