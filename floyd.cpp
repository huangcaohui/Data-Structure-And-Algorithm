#include "graph.h"

void Floyd(Graph &G, Dist **&D)
{
    int i,j,v;
    D = new Dist*[G.VerticesNum()];     //申请空间

    for(i = 0; i < G.VerticesNum(); i++)
        D[i] = new Dist[G.VerticesNum()];

    for(i = 0; i < G.VerticesNum(); i++)    //初始化数组D
        for(j = 0; j < G.VerticesNum(); j++)
        {
            if(i == j)
            {
                D[i][j].length = 0;
                D[i][j].pre = i;
            }
            else
            {
                D[i][j].length = INFINITE;
                D[i][j].pre = -1;
            }
        }

    for(v = 0; v < G.VerticesNum(); v++)
        for(Edge e = G.FirstEdge(v); G.IsEdge(e); e = G.NextEdge(e))
        {
            D[v][G.ToVertex(e)].length = G.Weight(e);
            D[v][G.ToVertex(e)].pre = v;
        }

    //加入新结点后，更新那些变短的路径长度
    for(v = 0; v < G.VerticesNum(); v++)
        for(i = 0; i < G.VerticesNum(); i++)
            for(j = 0; j < G.VerticesNum(); j++)
                if(D[i][j].length > D[i][v].length + D[v][j].length)
                {
                    D[i][j].length = D[i][v].length + D[v][j].length;
                    D[i][j].pre = D[v][j].pre;
                }
}