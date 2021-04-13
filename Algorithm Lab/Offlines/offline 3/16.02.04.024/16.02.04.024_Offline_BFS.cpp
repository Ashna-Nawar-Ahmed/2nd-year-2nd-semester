#include <bits/stdc++.h>
using namespace std;
#define WHITE 0
#define GRAY 1
vector <int>adj[25];
queue <int>q;
int color[25];
int parent[25];
int dis[25];
void bfs(int s,int v);
int main()
{
    int v,e;
    printf("Enter the number of vertices:");
    scanf("%d",&v);
    printf("Enter the number of edges:");
    scanf("%d",&e);
    for(int i=0; i<e; ++i)
    {
        printf("Enter the edges:");
        int u,v;
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);

    }

    for(int i = 1; i<=v; i++)
    {
        if(color[i] == WHITE)
        {
            printf("BFS path is: ");
            bfs(i,v);
            cout << endl;

        }
    }
}

void bfs(int s,int v)
{
    for(int i = 1 ; i <= v ; i++)
    {
        if(i!= s)
        {
            color[i] = WHITE;
            dis[i] = INT_MIN;
            parent[i] = NULL;
        }
    }

    color[s] = GRAY;
    dis[s] = 0;
    parent[s] = -1;
    q.push(s);
    color[s] = GRAY;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = 0; i<adj[u].size(); i++)
        {
            int v = adj[u][i];
            if(color[v] == WHITE)
            {
                color[v] = GRAY;
                dis[v] = dis[u]+1;
                parent[v] = u;
                q.push(v);
            }
        }
        cout << u <<" ";
    }
}
