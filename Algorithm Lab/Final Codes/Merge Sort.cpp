#include <bits/stdc++.h>

using namespace std;

void Merge(vector<int> &v, int s, int m, int e) {
    vector<int> l;
    vector<int> r;

    //int n1 = m - s + 1;
    //int n2 = e - m;

    for(int i = s; i <= m; ++i)
        l.push_back(v[i]);

    for(int i = m + 1; i <= e; ++i)
        r.push_back(v[i]);

    for(int i = s, il = 0, ir = 0; i <= e; ++i) {
        if(l[il] <= r[ir])
            v[i] = l[il++];
        else
            v[i] = r[ir++];
    }
}

void MS(vector<int> &v, int s, int e) {
    if(s < e) {
        int mid = (s + e) / 2;
        MS(v, s, mid);
        MS(v, mid + 1, e);
        Merge(v, s, mid, e);
    }
}

int main() {
    vector<int> v;

    int n;
    cin >> n;

    for(int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    MS(v, 0, n - 1);

    for(int i = 0; i < n; ++i) {
        cout << v[i] << " ";
    }
}
