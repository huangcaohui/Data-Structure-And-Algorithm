#include <iostream>

using namespace std;

template<class T>
class TreeNode  //树结点的ADT
{
private:
    T m_Value;  //树结点的值
    TreeNode<T> *pChild;    //第一个左孩子指针
    TreeNode<T> *pSibling;  //由兄弟指针

public:
    TreeNode(const T &value);   //拷贝构造函数
    virtual ~TreeNode() {};     //析构函数
    bool isLeaf();      //判断当前结点是否为叶节点
    T value();      //返回结点的值
    TreeNode<T> *LeftMostChild();   //返回第一个左孩子
    TreeNode<T> *RightSibling();    //返回右兄弟
    void setValue(const T &value);  //设置当前结点的值
    void setChild(TreeNode<T> *pointer);    //设置左孩子
    void setSibling(TreeNode<T> *pointer);  //设置左兄弟
    void InsertFirst(TreeNode<T> *node);    //以第一个左孩子身份插入结点
    void InsertNext(TreeNode<T> *node);     //以右兄弟的身份插入结点
};

template<class T>
class Tree
{
public:
    Tree();     //构造函数
    virtual ~Tree();    //析构函数
    TreeNode<T> *getRoot(); //返回树中的根结点
    void CreateRoot(const T &rootValue);    //创建值为rootValue的根节点
    bool isEmpty();     //判断是否为空树
    TreeNode<T> *Parent(TreeNode<T> *current);  //返回父结点
    TreeNode<T> *PreSibling(TreeNode<T> *current);  //返回前一个兄弟
    void DeleteSubTree(TreeNode<T> *subroot);   //删除以subroot子树
    void DestroyNodes(TreeNode<T> *root);   //删除以root为代表的所有结点
    void RootFirstTraverse(TreeNode<T> *root);  //先根深度优先遍历树
    void RootLastTraverse(TreeNode<T> *root);  //后根深度优先遍历树
    void WidthTraverse(TreeNode<T> *root);      //广度优先遍历树
};