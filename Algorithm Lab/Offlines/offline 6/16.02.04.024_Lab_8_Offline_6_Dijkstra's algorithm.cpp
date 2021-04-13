#include<bits/stdc++.h>
using namespace std;
int V,E;
struct vertex
{
    int distance,parent;
    vertex(int d,int p)
    {
        distance=d;
        parent=p;
    }
    bool operator<(vertex x) const
    {
        return distance < x.distance;
    }
};
vector<vertex> Graph;
priority_queue<vertex> q;
vertex Set[100];
void initialise(vertex s)
{
    for(int i=1; i<=V; i++)
    {
        Graph[i].distance=INT_MAX;
        Graph[i].parent=-1;
    }
    s.distance=0;
}
int relax(vertex u,vertex v,int w)
{
    if(v.distance>(u.distance+w))
    {
        v.distance=u.distance+w;
        v.parent=u;
    }
}
void dijkstra(int w,vertex s)
{
    int cnt=0;
    initialise(s);
    for(int i=1; i<=V; i++)
    {
        q.push(i);
    }
    while(!q.empty())
    {
        vertex u=q.top();
        q.pop();
        Set[cnt++]=u;
        for (int i = 0; i < Graph[u.distance].size(); i++)
        {
            vertex v = Graph[u.distance][i];
            relax(u,v,w);
        }
    }
}
int main()
{
    printf("Enter vertex and edge:");
    scanf("%d%d",&V,&E);
    for(int i=1;i<=V;i++)
    dijkstra();
}
