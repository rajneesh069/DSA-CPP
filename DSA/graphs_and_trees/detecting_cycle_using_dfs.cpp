// Cycle detection
/*
If there's a cycle, we reach a node which is already visited but it is not the
parent node from which we came from.
*/
#include <bits/stdc++.h>
using namespace std;

bool dfs(int v, int par, vector<int>g[], vector<bool>& vis) {
    vis[v] = true;
    bool does_loop_exist = false;
    for (int child : g[v]) {
        if (vis[child] && child == par) continue;
        if (vis[child] && child != par) {
            return true;
        };
        does_loop_exist |= dfs(child, v, g, vis);
    }
    return does_loop_exist;
}


int main() {
    int n, m;
    cin >> n >> m;
    vector<int>g[n + 1];
    for (int i = 0; i < m; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    vector<bool>vis(n + 1, false);
    for (int i = 0; i < vis.size(); i++) {
        if (vis[i]) continue;
        if (dfs(i, 0, g, vis)) {
            cout << "true" << "\n";
            return 0;
        };
    }

    cout << "false" << "\n";

    return 0;
}