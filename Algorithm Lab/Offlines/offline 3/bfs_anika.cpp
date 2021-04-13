#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector <int>adj[25];
queue <int>q;
int color[25];
void bfs(int s){
    q.push(s);
    color[s] = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i = 0;i<adj[u].size();i++) {
            int v = adj[u][i];
            if(color[v] == 0) {
                color[v] = 1;
                q.push(v);
            }
        }
        cout << u <<" ";
    }
}
int main(){
    int v,e;
    cin>> v >>e;
    while(e--){
        int x,y;
        cin >> x >>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i = 0;i<v;i++) {
        if(color[i] == 0) {
            bfs(i);
            cout << endl;
        }
    }
}
