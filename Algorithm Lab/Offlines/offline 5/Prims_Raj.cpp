#include<bits/stdc++.h>
using namespace std;
int arr[100][100];
struct nodes
{
    int n;
    int w = INT_MAX;
    int p = -1;
    bool operator < (const nodes &a) const
    {
        return w > a.w;
    }
};

int main()
{

    int vertex, edge, cost = 0;
    printf("Enter no. of Vertex : ");
    scanf("%d",&vertex);
    printf("Enter no. of Edge : ");
    scanf("%d",&edge);
    priority_queue <nodes> pq;
    nodes prim[vertex];

    for(int i = 1 ; i <= edge ; i++)
    {
        int u, v, w;
        printf("Enter starting point, ending point and weight of edge:\n");
        scanf("%d %d %d",&u,&v,&w);
        arr[u][v] = w;
    }
    prim[1].n = 0;
    prim[1].w = 0;
    prim[1].p= 0;

    for(int i = 1 ; i <= vertex ; i++)
    {
        prim[i].n = i;
        pq.push(prim[i]);
    }
    for(int i = 1; !pq.empty(); i++)
    {
        nodes u = pq.top();
        pq.pop();
        for(int v = 1 ; v <= vertex ; v++)
        {
            if(arr[u.n][v] != 0)
            {
                if(arr[u.n][v] < prim[v].w)
                {
                    prim[v].p = u.n;
                    prim[v].w = arr[u.n][v];
                }
            }
        }
    }
    printf("Minimum Spanning Tree: \n");
    for(int i = 2 ; i <= vertex ; i++)
    {
        printf("starting point:%d ending point:%d weight:%d\n",prim[i].n,prim[i].p,prim[i].w);
        cost = cost + prim[i].w;
    }
    printf("Minimum cost: %d\n",cost);
    return 0;
}

