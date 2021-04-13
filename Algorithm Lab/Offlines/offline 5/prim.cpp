#include<bits/stdc++.h>
using namespace std;
struct node
{
    int startp;
    int cost;
};
struct edges
{
    int first;
    int second;
};
vector<edges> v[100];
priority_queue<node> q;
int cost[100];
bool taken[100];
int vertex,edge;
bool operator<(node x,node y);
int prim(int source);
void printer();
int main()
{
    printf("Enter number of vertex and edge:");
    scanf("%d %d",&vertex,&edge);
    for(int i=0;i<edge;i++){
        int source;
        edges ed;
        printf("\nEnter source,starting point and ending point:");
        scanf("%d %d %d",&source,&ed.first,&ed.second);
        v[source].push_back(ed);
        int source2=ed.first;
        ed.first=source;
        v[source2].push_back(ed);
    }
    printf("\nMST is:");
    printer();

}
bool operator<(node x,node y)
{
    return x.cost>y.cost;
}
int prim(int source)
{
    for(int i=0;i<vertex;i++)
    {
        cost[i]=INT_MAX;
        taken[i]=false;
    }
    cost[source]=0;
    node temp;
    temp.startp=source;
    temp.cost=0;
    q.push(temp);
    int val=0;
    while(!q.empty()){
        node current=q.top();
        q.pop();
        if(taken[current.startp]){
            continue;
        }
        taken[current.startp]=true;
        val+=current.cost;

        for(int i=0;i<v[current.startp].size();i++){
            if(taken[v[current.startp][i].first]){
                continue;
            }
            if(v[current.startp][i].second<cost[v[current.startp][i].first]){
                node temp2;
                temp2.startp=v[current.startp][i].first;
                temp2.cost=v[current.startp][i].second;
                q.push(temp2);
                cost[v[current.startp][i].first]=v[current.startp][i].second;
            }
        }
    }
    return val;
}
void printer()
{
    for(int i=0;i<vertex;i++)
    {
        printf("%d:",i);
        for(int j=0;j<v[i].size();j++){
            printf("%d-%d\n",v[i][j].first,v[i][j].second);
        }
    }
}
