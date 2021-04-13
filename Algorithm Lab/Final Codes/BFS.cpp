#include <bits/stdc++.h>

using namespace std;

vector<int> adj[105];
int color[105];

void BFS(int s) {
    color[s] = 1;
    queue<int> q;

    q.push(s);

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        cout << u << " is visited" << endl;

        int sz = adj[u].size();

        for(int i = 0; i < sz; ++i) {
            int v = adj[u][i];
            if(color[v] == 0) {
                color[v] = 1;
                q.push(v);
            }
        }
    }
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
        adj[v].push_back(u);
    }

    cout << "Enter the starting node: ";
    int s;
    cin >> s;

    cout << "BFS traversal for starting node " << s << " is" << endl;
    BFS(s);
}
