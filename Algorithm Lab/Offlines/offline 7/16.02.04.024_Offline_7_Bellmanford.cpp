#include<bits/stdc++.h>
using namespace std;
struct edge
{
    int s,e,cost;
    edge(int S,int E,int Cost)
    {
        s=S;
        e=E;
        cost=Cost;
    }
};
vector<edge>edges;
int parent[100],dist[100];
int Edge,source,Vertex;
void initializeSingleSource(int source);
bool Bellmanford();
int main()
{

    printf("Enter number of edges:");
    scanf("%d",&Edge);
    printf("Enter number of vertices:");
    scanf("%d",&Vertex);
    for(int i=0; i<Edge; i++)
    {
        printf("Enter starting point ending point and cost of edge:");
        int x,y,c;
        scanf("%d%d%d",&x,&y,&c);
        edges.push_back(edge(x,y,c));
    }
    printf("Enter source:");
    scanf("%d",&source);
    parent[source]=0;
    dist[source]=0;
    bool negCycle=Bellmanford();
    if(!negCycle)
    {
        printf("Negative cycle exists\n");
    }
    else
    {
        printf("\nParent array:");
        for(int i=1; i<=Vertex; i++)
            printf("%d ",parent[i]);
        printf("\nDistances:");
        for(int i=1; i<=Vertex; i++)
            printf("\nDistance of %d is %d ",i,dist[i]);
    }

}
void initializeSingleSource(int source)
{
    for(int i=1; i<=Vertex; i++)
    {
        parent[i]=i;
        if(i!=source)
        {
            dist[i]=INT_MAX;
        }
        else
        {
            dist[i]=0;
        }
    }
}
bool Bellmanford()
{
    initializeSingleSource(source);
    for(int i=1; i<Vertex; i++)
    {
        for(int j=0; j<Edge; j++)
        {
            int u=edges[j].s;
            int v=edges[j].e;
            int w=edges[j].cost;
            if(dist[u] != INT_MAX && dist[v]>dist[u] + w)
            {
                dist[v]=dist[u] + w ;
                parent[v]=u;
            }

        }
    }

    for(int i=0; i<Edge; i++)
    {
        int u=edges[i].s;
        int v=edges[i].e;
        int w=edges[i].cost;
        if(dist[u] != INT_MAX && dist[v]>dist[u] + w)
        {
            return false;
        }

    }
    return true;

}
