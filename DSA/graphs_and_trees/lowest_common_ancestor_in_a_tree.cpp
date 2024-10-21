#include <bits/stdc++.h>
using namespace std;


void dfs(int v, int p, vector<vector<int>>& g, vector<int>& par) {
    par[v] = p;
    for (int c : g[v]) {
        if (c == p) continue;
        dfs(c, v, g, par);
    }
}

vector<int> path(int v, vector<int>& par) {
    vector<int> p;
    while (v != -1) {
        p.push_back(v);
        v = par[v];
    }
    reverse(p.begin(), p.end());
    return p;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>>g(n + 1);
    vector<int> par(n + 1, -1);
    for (int i = 0; i < n - 1; i++) {
        int x, y; cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    // take any 2 nodes for their LCA, suppose 2 and 12 -> their LCA is 2
    dfs(1, -1, g, par);

    vector<int>p1 = path(12, par);
    vector<int>p2 = path(2, par);

    for (auto& it : p1) {
        cout << it << " ";
    }
    cout << "\n";
    
    for (auto& it : p2) {
        cout << it << " ";
    }
    cout << "\n";

    int LCA = -1;
    for (int i = 0; i < n-1; i++) {
        if (p1[i] != p2[i]) break;
        LCA = p1[i];
    }

    cout << LCA;
    return 0;
}