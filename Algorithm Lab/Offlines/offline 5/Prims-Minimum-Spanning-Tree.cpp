#include <bits/stdc++.h>

using namespace std;

#define mx 10005
#define pii pair<long long, int>

bool marked[mx];
vector <pii> adj[mx];

long long prim(int x)
{
    priority_queue<pii, vector<pii>, greater<pii> > Q;
    int y;
    long long minimumCost = 0;
    pii p;
    Q.push(make_pair(0, x));
    while(!Q.empty())
    {
        p = Q.top();
        Q.pop();
        x = p.second;
        if(marked[x] == true){
            continue;
        }
        minimumCost += p.first;
        marked[x] = true;
        for(int i = 0;i < adj[x].size();++i)
        {
            y = adj[x][i].second;
            if(marked[y] == false)
                Q.push(adj[x][i]);
        }
    }
    return minimumCost;
}

int main()
{
    int nodes, edges, x, y;
    long long weight, minimumCost;
    cin >> nodes >> edges;
    for(int i = 0;i < edges;++i)
    {
        cin >> x >> y >> weight;
        adj[x].push_back(make_pair(weight, y));
        adj[y].push_back(make_pair(weight, x));
    }

    minimumCost = prim(1);
    cout << minimumCost << endl;
    return 0;
}
