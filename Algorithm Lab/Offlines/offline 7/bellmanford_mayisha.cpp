#include<bits/stdc++.h>
using namespace std;
int par[100];
int dis[100];
int n,e;
#define inf 999999
struct edge
{
    int u,v,w;
};
int main()
{
    cout<<"Enter the nodes and edges:";
    cin>>n>>e;
    int s;
    vector<edge>vec;
    for(int i=0; i<e; i++)
    {
        edge e;
        cin>>e.u>>e.v>>e.w;
        vec.push_back(e);
    }
    for(int i=0; i<=n; i++)
    {
        dis[i] = inf;
    }
    cout<<"Enter source";
    cin>>s;

    dis[s] = 0;

    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<vec.size(); j++)
        {
            edge e=vec[j];
            int u=e.u;
            int v=e.v;
            int w=e.w;
            if(dis[u]+w<dis[v])
            {
                dis[v]=dis[u]+w;
            }
        }


    }

    for(int j=0; j<e; j++)
    {
        edge e=vec[j];
        int u=e.u;
        int v=e.v;
        int w=e.w;
        if(dis[u]+w<dis[v])
        {

            cout<<endl<<"There graph contains negative cycle";
            cout<<endl;
        }
    }



    for(int i = 0; i < n; i++)
    {
        cout << "Distance of "<< i << " is : " << dis[i] << endl;
    }
    return 0;

}
