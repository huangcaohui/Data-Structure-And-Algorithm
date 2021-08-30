#include <iostream>
#include <limits>

using namespace std;

class Edge
{
public:
    int from, to, weight;   //边的始点，终点，权

    Edge()  //缺省构造函数
    {
        from = -1; to = -1; weight = 0;
    }

    Edge(int f, int t, int w)   //给定参数的构造函数
    {
        from = f; to = t; weight = w;
    }
};

class Graph     //图的ADT
{
public:
    int numVertex;  //图中顶点的个数
    int numEdge;    //图中边的条数
    int *Mark;  //图的顶点访问标记
    int *Indegree;  //存放图中顶点的入度

    int VerticesNum();  //返回图的顶点个数
    int EdgesNum();     //返回图的边数
    Edge FirstEdge(int oneVertex);  //第一条关连边
    Edge NextEdge(Edge perEdge);    //下一条兄弟边
    bool setEdge(int fromVertex, int toVertex, int weight); //添加一条边
    bool delEdge(int fromVertex, int toVertex); //删边
    bool IsEdge(Edge oneEdge);  //判断oneEdge是否
    int FromVertex(Edge oneEdge);   //返回边的始点
    int ToVertex(Edge oneEdge); //返回边的终点
    int Weight(Edge oneEdge);   //返回边的权
}; 

bool UNVISITED = 0;
bool VISITED = 1;
bool INFINITE = INT_MAX;

class Dist  //Dist类，用于保存最短路径信息
{
public:
    int index;  //结点的索引值，仅Dijkstra
    int length; //当前最短路径长度
    int pre;    //路径最后经过的结点，其前驱结点
};