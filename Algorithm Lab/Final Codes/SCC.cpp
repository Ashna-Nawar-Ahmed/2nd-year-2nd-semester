#include <bits/stdc++.h>

#define WHITE 0
#define GREY 1
#define BLACK 2

using namespace std;

vector<int> adj[105];
vector<int> revadj[105];
int color[105];
stack<int> scc;

void DFS(int u) {
    color[u] = GREY;

    int sz = adj[u].size();
    for(int i = 0; i < sz; ++i) {
        int v = adj[u][i];

        if(color[v] == WHITE)
            DFS(v);
    }

    color[u] = BLACK;
    scc.push(u);
}

void DFS2(int u) {
    color[u] = GREY;

    int sz = revadj[u].size();
    for(int i = 0; i < sz; ++i) {
        int v = revadj[u][i];

        if(color[v] == WHITE)
            DFS2(v);
    }

    cout << u << " ";
}

int main() {
    cout << "Enter the number of vertices: ";
    int V;
    cin >> V;

    cout << "Enter the number of edges: ";
    int E;
    cin >> E;

    cout << "Enter the edges:" << endl;
    for(int i = 0; i < E; ++i) {
        cout << "u v: ";
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        revadj[v].push_back(u);
    }

    cout << endl;
    for(int i = 1; i <= V; ++i) {
        if(color[i] == WHITE) {
            DFS(i);
        }
    }

    memset(color, WHITE, sizeof(color));

    cout << "The SCCs are:" << endl;

    while(!scc.empty()) {
        int i = scc.top();
        scc.pop();

        if(color[i] == WHITE) {
            DFS2(i);
            cout << endl;
        }
    }
}
