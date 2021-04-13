#include<bits/stdc++.h>
using namespace std;
int pi[50];
int mstSet[50];
int key[50];
int graph[50][50];
int V,E;
#define true 1
#define false 2
int minKey(int key[],int mstSet[])
{
    int minVal=INT_MAX;
    int min_index;
    for(int v=0;v<E;v++)
    {
        if(mstSet[v]==false && key[v]<minVal)
        {
            minVal=key[v];
            min_index=v;
        }
    }
    return min_index;
}
void primMST()
{

    for(int i=0;i<E;i++)
    {

        key[i]=INT_MAX;
        mstSet[i]=false;
    }
    key[0]=0;
    pi[0]=-1;
    for(int cnt=0;cnt<E-1;cnt++)
    {
        int u=minKey(key,mstSet);
        mstSet[u]=true;

        for(int v=0;v<E;v++)
        {
            if(graph[u][v] && mstSet[v]==false && graph[u][v]<key[v] )
            {
                pi[v]=u;
                key[v]=graph[u][v];
            }
        }
    }
}
int main()
{
    printf("Enter number of edges:");
    scanf("%d",&E);
    printf("Enter number of vertices:");
    scanf("%d",&V);
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            printf("enter weight between %d %d",i,j);
            int x;
            scanf("%d",&x);
            graph[i][j]=x;
            graph[j][i]=x;
        }
    }
     primMST();
     printf("Minimum spanning tree:\n");
     for(int i=1;i<E;i++)
     {
         printf("%d-%d %d\n",pi[i],i,graph[i][pi[i]]);
     }
     return 0;
}
