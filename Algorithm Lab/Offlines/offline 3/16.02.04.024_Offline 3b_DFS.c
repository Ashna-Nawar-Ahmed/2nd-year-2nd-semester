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
    dfs(V);
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
            dfsvisit(h,v);
        }
    }

    colour[u] = BLACK;
    time++;
    dis[u]=time;
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
            dfsvisit(i,v);
        }
    }
}


