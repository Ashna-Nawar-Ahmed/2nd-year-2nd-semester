#include<bits/stdc++.h>
using namespace std;
#define White 0
#define Gray 1
#define Black 2
int node,edge;
int color [100];
int componentCount=1;
vector <int> adj[100];
vector<int> adjRev[100];
stack<int> s;
void dfsVisit(int x);
void dfs();
void dfsVisitSCC(int x);
void dfsSCC();
int main()
{
    printf("Enter no. of nodes:");
    scanf("%d",&node);
    printf("Enter no. of edges:");
    scanf("%d",&edge);
    for(int i=0; i<edge; i++)
    {
        printf("Enter an edge:");
        int u,v;
        scanf("%d %d",&u,&v);
        adj[u].push_back(v);
        adjRev[v].push_back(u);
    }
    dfs();
    dfsSCC();

}
void dfsVisit(int x)
{
    color[x]=Gray;
    for(int i=0; i<adj[x].size(); i++)
    {
        int u=adj[x][i];
        if(color[u]==White)
            dfsVisit(u);
    }

    s.push(x);
    color[x]=Black;

}
void dfs()
{
    for(int i=1; i<=node; i++)
        color[i]=White;

    for(int i=1; i<=node; i++)
    {
        if(color[i]==White)
            dfsVisit(i);

    }

}
void dfsVisitSCC(int x)
{
    color[x]=Gray;
    printf("%d ",x);
    for(int i=0; i<adjRev[x].size(); i++)
    {
        int u=adjRev[x][i];
        if(color[u]==White)
            dfsVisitSCC(u);
    }
    color[x]=Black;
}

void dfsSCC()
{
    for(int i=1; i<=node; i++)
        color[i]=White;
    while(!s.empty())
    {
        int u=s.top();
        if(color[u]==White)
        {
            printf("\nComponent %d:\n",componentCount++);
            dfsVisitSCC(u);
        }
        s.pop();
    }

}

