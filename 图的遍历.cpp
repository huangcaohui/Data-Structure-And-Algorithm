#include "graph.h"

void Do_topsort(Graph &G, int V, int *result, int &index)
{
    G.Mark[V] = VISITED;

    for(Edge e = G.FirstEdge(V); G.IsEdge(e); e = G.NextEdge(e))
    {
        if(G.Mark[G.ToVertex(e)] == UNVISITED)
            Do_topsort(G, G.ToVertex(e), result, index);
    }
    result[index++] = V;
}

//深度优先搜索实现的拓扑排序
int *TopsortbyDFS(Graph &G)     //结果是颠倒的
{
    for(int i = 0; i < G.VerticesNum(); i++)    //初始化
        G.Mark[i] = UNVISITED;

    int *result = new int[G.VerticesNum()];
    int index = 0;

    for(i = 0; i < G.VerticesNum(); i++)    //对所有顶点
        if(G.Mark[i] = UNVISITED)
            Do_topsort(G, i, result, index);    //递归函数

    for(i = G.VerticesNum()-1; i >= 0; i--)     //逆序输出
        Visit(G, result[i]);

    return result;
}