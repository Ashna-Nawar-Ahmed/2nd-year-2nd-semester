#include<bits/stdc++.h>
using namespace std;
struct edge
{
    int s,e,ecost,vcost;
    edge(int S,int E,int eCost)
    {
        s=S;
        e=E;
        ecost=eCost;
    }
};
vector<edge>edges;
int p[100],dist[100];
int Edge,source,Vertex;
void initializeSingleSource(int source);
void pathPrinter(int src);
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
        p[x]=x;
        p[y]=y;
        dist[x]=INT_MAX;
        dist[y]=INT_MAX;
    }
    printf("Enter source:");
    scanf("%d",&source);
    p[source]=0;
    dist[source]=0;
    bool negCycle=Bellmanford();
    if(!negCycle)
    {
        printf("Negative cycle exists\n");
    }
    printf("Shortest Path is:");
    pathPrinter(source);
    printf("\nParent array:");
    for(int i=1;i<=Vertex;i++)
        printf("%d ",p[i]);
    printf("\nDistance array:");
    for(int i=1;i<=Vertex;i++)
        printf("%d ",dist[i]);
}
void pathPrinter(int src)
{
    printf("%d ",src);
    for(int i=1;i<=Vertex;i++)
    {
        if(p[i]==src)
            pathPrinter(i);
    }

}
void initializeSingleSource(int source)
{
    for(int i=1; i<=Vertex; i++)
    {
        if(i!=source)
        {
            edges[i].vcost=INT_MAX;
        }
        else
        {
            edges[i].vcost=0;
        }
    }
}
bool Bellmanford()
{
    initializeSingleSource(source);
    for(int i=1; i<Vertex; i++)
    {
        for(int i=0; i<Edge; i++)
        {
            int u=edges[edges[i].s].vcost;
            int v=edges[edges[i].e].vcost;
            int w=edges[i].ecost;
            if(v>(u+w))
            {
                edges[edges[i].e].vcost=u+w;
                p[edges[i].e]=edges[i].s;
                dist[edges[i].e]=u+w;
            }

        }
    }

    for(int i=0; i<Edge; i++)
    {
        int u=edges[edges[i].s].vcost;
        int v=edges[edges[i].e].vcost;
        int w=edges[i].ecost;
        if(v>(u+w))
        {
            return false;
        }
    }
    return true;

}
