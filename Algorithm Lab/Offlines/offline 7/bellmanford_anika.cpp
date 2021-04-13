#include<bits/stdc++.h>
using namespace std;


int d[100],parent[100];

struct edge
{
    int u,v,w;
};
vector<edge> edges;

void relax(int u,int v,int w)
{
    if(d[v]>(d[u]+w))
    {
        d[v]=(d[u]+w);
        parent[v]=u;
    }
}

void find_path(int des)
{

    if(parent[des]==-1)
    return;
   else
    find_path(parent[des]);
   cout<<" "<<des<<" ";


}

void bellFord(int st,int nodes)
{

     for(int i=0;i<nodes;i++)
    {
        d[i]=INT_MAX;
        parent[i]=-1;
    }

    d[st]=0;
    for(int i=0;i<nodes-1;i++)
    {
        int sz = edges.size();
        for(int j=0;j<sz;j++)
        {
            edge e=edges[j];
            relax(e.u,e.v,e.w);
        }
    }
    int sz=edges.size();

    for(int i=0;i<sz;i++)
    {
        edge e=edges[i];
        if(d[e.v]>(d[e.u]+e.w))
        {
            cout<<"\nThere is a negative loop in the graph.....\n";
            return;
        }
    }



   cout<<"Distance from all node from source and path"<<endl;
   cout<<"Source->Destination\tDistance\tPath"<<endl;

   for(int i=0;i<nodes;i++)
   {
       cout<<"   "<<st<<"  ->   "<<i<<"\t     :\t   "<<d[i]<<"\t\t";
       if(i>0)
       {
          cout<<st<<" ";
         find_path(i);
       }
       else
       {
         //cout<<"No path";
         cout<<"No Path";
         //cout<<"1";
       }
       cout<<endl;
   }

}

int main()
{
    int N,E;
    cout<<"Nodes: ";
    cin>>N;
    cout<<"Edges: ";
    cin>>E;



    cout<<"Input Graph:\n";
    for(int i=0;i<E;i++)
    {
        edge a;
        cin>>a.u>>a.v>>a.w;
        edges.push_back(a);
    }
    //cout<<"Input Start and End point:";
   // int st,en;
    //cin>>st;
    bellFord(0,N);

    return 0;
}
