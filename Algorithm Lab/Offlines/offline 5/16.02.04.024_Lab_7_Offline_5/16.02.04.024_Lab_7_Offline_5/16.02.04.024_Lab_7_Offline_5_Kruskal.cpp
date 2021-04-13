#include<bits/stdc++.h>
using namespace std;
struct edge{
    int s,e,w;
    edge(int _s,int _e,int _w){
        s=_s;
        e=_e;
        w=_w;
    }
};
vector<edge>edges;
int parent[100];
bool compare(edge a,edge b);
int findset(int x);
void kruskal(int e);
int main(){
    int e;
    printf("Enter number of edges:");
    scanf("%d",&e);
    for(int i=0;i<e;i++){
        printf("Enter starting point, ending point and weight of edge:");
        int x,y,w;
        scanf("%d%d%d",&x,&y,&w);
        edges.push_back(edge(x,y,w));
        parent[x]=x;
        parent[y]=y;
    }
    sort(edges.begin(),edges.end(),compare);
    kruskal(e);
}


bool compare(edge a,edge b){
    return a.w<b.w;
}

int findset(int x){
    if(parent[x]==x)
        return x;
    return findset(parent[x]);

}

void kruskal(int e){
    int mincost=0;
    printf("Minimum Spanning Tree: \n");

    for(int i=0;i<e;i++){

        int sroot=findset(edges[i].s);
        int eroot=findset(edges[i].e);
        int cost=edges[i].w;

        if(sroot!=eroot){
            parent[sroot]=parent[eroot];
            printf("starting point:%d ending point:%d weight:%d\n",edges[i].s,edges[i].e,edges[i].w);
            mincost+=cost;
        }
    }
    printf("Minimum Cost : %d",mincost);
}
