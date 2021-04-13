#include<stdio.h>
#include<vector>
#define WHITE 0
#define GRAY 1
#define BLACK 2
using namespace std;

int V,E;
vector<int>adj[200];
int colour[200];
int parent[200];
int dis[200];
int h[100];
int height=0;
int time;
void dfsvisit(int u,int v);
void dfs(int v);
int main()
{

    printf("Enter the number of vertices:");
    scanf("%d",&V);
    printf("Enter the number of edges:");
    scanf("%d",&E);
    for(int i=0; i<E; ++i)
    {
        printf("Enter the edges:");
        int u,v;
        scanf("%d %d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    printf("DFS path is: ");
    dfs(V);
    for(int i=1;i<=V;i++)
        printf("\n\nHeight: %d",(h[i])/2);
}
void dfsvisit(int u,int v)
{
    time++;
    colour[u]=GRAY;
    dis[u]=time;
    printf("%d ",u);
    int s=adj[u].size();
    for(int k=0; k<s; ++k)
    {
        int h=adj[u][k];
        if(colour[h]== WHITE)
        {
            parent[h]=u;
            height++;
            dfsvisit(h,v);
        }
    }
    colour[u] = BLACK;
    time++;
    dis[u]=time;
    h[u]=height;
}

void dfs(int v)
{
    for(int i=0; i<v; ++i)
    {
        colour[i]=WHITE;
        parent[i]=-1;
    }
    time=0;
    for(int i=1; i<=v; i++)
    {
        if(colour[i]==WHITE)
        {
            height=1;
            dfsvisit(i,v);
        }
    }
}


