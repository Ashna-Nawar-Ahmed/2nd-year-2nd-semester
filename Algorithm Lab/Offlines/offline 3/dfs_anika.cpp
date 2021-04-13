#include<stdio.h>
#include<vector>
#define WHITE 0
#define GRAY 1
#define BLACK 2
using namespace std;

int V,E;
vector<int>neighbour[200];
int colour[200];
int parent[200];
void dfsvisit(int u,int v)
{
    colour[u]=GRAY;
    printf(" %d",u);
    int s=neighbour[u].size();
    for(int k=0;k<s;++k)
    {
        int h=neighbour[u][k];
        //printf("neighbour %d",h);
        if(colour[h]== WHITE)
        {
            parent[h]=u;
            dfsvisit(h,v);
        }
    }

   colour[u] = BLACK;
    // printf("%d\t",u);
}

void dfs(int v)
{
    for(int i=0;i<v;++i)
        colour[i]=WHITE;
    for(int i=0;i<v;i++)
    {
        if(colour[i]==WHITE)
        {
            dfsvisit(i,v);
        }
    }
}

int main()
{
    printf("Enter the number of vertices:");
    scanf("%d",&V);
     printf("Enter the number of edges:");
    scanf("%d",&E);
    for(int i=0;i<E;++i)
    {
        printf("Enter the edges:");
        int u,v;
        scanf("%d%d",&u,&v);
        neighbour[u].push_back(v);
        neighbour[v].push_back(u);

    }
    dfs(V);
}
