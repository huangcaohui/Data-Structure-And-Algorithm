#include "graph.h"
#include "minHeap.h"

void Dijkstar(Graph &G, int s, Dist *&D)    //s是源点
{
    D = new Dist[G.VerticesNum()];  //记录当前最短路径长度

    for(int i = 0; i < G.VerticesNum(); i++)    //初始化
    {
        G.Mark[i] = UNVISITED;
        D[i].index = i;
        D[i].length =  INFINITE;
        D[i].pre = s;
    }

    D[s].length = 0;    //源点到自身的路径长度置为0
    MinHeap<Dist> H(G.EdgesNum());  //最小值堆用于找出最短路径
    H.Insert(D[s]);

    for(int i = 0; i < G.VerticesNum(); i++)
    {
        bool FOUND = false;
        Dist d;
        
        while(!H.isEmpty())
        {
            d = H.RemoveMin();  //获得到s路径长度最小的结点
            if(G.Mark[d.index] == UNVISITED)    //如果未访问过则跳出循环
            {
                FOUND = true;
                break;
            }
        }

        if(!FOUND)  //若没有符合条件的最短路径则跳出本次循环
            break;

        int v = d.index;
        G.Mark[v] = VISITED;    //将标记位设置为VISITED

        for(Edge e = G.FirstEdge(v); G.IsEdge(e); e = G.NextEdge(e))  //刷新最短路
        {
            if(D[G.ToVertex(e)].length > D[v].length+G.Weight(e))
            {
                D[G.ToVertex(e)].length = D[v].length + G.Weight(e);
                D[G.ToVertex(e)].pre = v;
                H.Insert(D[G.ToVertex(e)]);
            }
        }
    }
}