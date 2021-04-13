#include<bits/stdc++.h>
#define INF 9999999
using namespace std;
int main()
{
    int dis[100][100],V,E;
    printf("enter v & e:");
    scanf("%d %d",&V,&E);
    for(int i=0; i<=V; i++)
    {
        for(int j=0; j<=V; j++)
        {
            if(i==j)
                dis[i][j]=0;
            else dis[i][j]=INF;
        }
    }
    printf("Enter the edges:");
    for(int i=0; i<E; i++)
    {
        int x,y,w;
        scanf("%d%d%d",&x,&y,&w);
        dis[x][y]=w;
    }
    for(int k=1; k<=V; k++)
    {
        for(int i=1; i<=V; i++)
        {
            for(int j=1; j<=V; j++)
            {
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    for(int i=1; i<=V; i++)
    {
        for(int j=1; j<=V; j++)
        {
            if(dis[i][j]==INF)
                printf("%d %d INF\n",i,j);
            else
                printf("%d %d %d\n",i,j,dis[i][j]);
        }
    }
}
