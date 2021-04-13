#include<bits/stdc++.h>
using namespace std;
#define W 0
#define G 1
#define B 2
vector<int> adj[25];
stack<int> st;
int color[100],dis[100],parent[100],t,v,e;
void dfs(int v);
void DFS_Visit(int v);
int main()
{
    printf("Enter v and e:");
    scanf("%d %d",&v,&e);
    for(int i=0;i<e;i++)
    {
        int a,b;
        printf("\nEnter edge:");
        scanf("%d %d",&a,&b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    printf("\nDFS path: ");
    dfs(v);
    printf("\nTopological sort: ");
    for(int i=0;i<st.size();i++)
    {
        int x;
        x=st.top();
        st.pop();
        printf("%d ",x);
    }
}
void dfs(int v)
{
    for(int i=1;i<=v;i++)
    {
        color[i]=W;
        parent[i]=-1;
    }
    t=0;
    for(int i=1;i<=v;i++)
    {
        if(color[i]==W)
            DFS_Visit(i);
    }
}
void DFS_Visit(int v)
{
    t++;
    dis[v]=t;
    color[v]=G;
    //printf("%d ",v);
    int sz=adj[v].size();
    for(int i=0;i<sz;i++)
    {
        int u=adj[v][i];
        if(color[u]==W)
        {
            parent[u]=v;
            DFS_Visit(u);
        }
    }
    t++;
    dis[v]=t;
    color[v]=B;
    if(color[v]==B)
        st.push(v);
    printf("%d ",v);
    //st.push(v);

}
