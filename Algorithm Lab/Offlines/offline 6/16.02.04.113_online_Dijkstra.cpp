//given a directed weighted graph where all edges are non negative . write a program to find shortest path distance and the path itself for all nodes from source node s
#include<bits/stdc++.h>
using namespace std;
#define no 1
#define yes 2
struct vertex
{
    int parent;
    int index;
    int visited;
    int vweight;
};
struct vertex n[100];
vector<int>adj[100];
vector<int>edgeWeight[100];
int Vertex,Edge,root;
bool operator<(const vertex &n1,const vertex &n2)
{
    return n1.vweight>n2.vweight;
}
void Dijkstra();
int main()
{
    printf("Enter vertex and edge number:");
    scanf("%d %d",&Vertex,&Edge);
    printf("Source: ");
    scanf("%d",&root);
    printf("\nEnter starting point, ending point and distance:\n");
    for(int i=0;i<Edge;i++)
    {
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        adj[u].push_back(v);
        edgeWeight[u].push_back(w);
    }
    for(int i=root;i<=Vertex;i++)
    {
        n[i].visited=no;
        n[i].index=i;
        n[i].vweight=INT_MAX;
        n[i].parent=i;
    }
    Dijkstra();
    return 0;

}

void Dijkstra()
{
    n[root].vweight=0;
    priority_queue<vertex>pq;

    pq.push(n[root]);

    while(!pq.empty())
    {
        struct vertex temp=pq.top();
        int u= temp.index;
        pq.pop();
        int sz=adj[u].size();
        for(int i=0;i<sz;i++)
        {
            int v=adj[u][i];
            if(n[v].visited==no && n[v].vweight > n[u].vweight+edgeWeight[u][i] )
            {
                n[v].vweight=n[u].vweight+edgeWeight[u][i];
                n[v].parent=u;
                pq.push(n[v]);

            }
        }
        n[u].visited=yes;

    }
    for(int i=root;i<=Vertex;i++)
    {

        printf("%d %d ",n[i].index,n[i].vweight);
    /*
            for(int j=root;j<=i;j++)
        {
            printf("%d",n[j].index);
        }
*/

        printf("\n");

    }

}
