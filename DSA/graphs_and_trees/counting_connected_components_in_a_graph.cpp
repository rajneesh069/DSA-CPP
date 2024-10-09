#include <bits/stdc++.h>
using namespace std;


void dfs(int vertex, vector<int> g[], vector<bool>& vis) {
    // take action on vertex after entering the vertex
    vis[vertex] = true;
    for (int child : g[vertex]) {
        // take action on child before entering the child node(haven't called dfs yet)
        if (vis[child]) continue;
        dfs(child, g, vis);
        // take action on child after exiting the child node(called dfs on child)
    }
    // take action on vertex before exiting the vertex
}



int main() {
    int n, m;
    cin >> n >> m;
    vector<int> g[n + 1];
    vector<bool>vis(n + 1, false);
    for (int i = 0; i < m; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    int count = 0;
    for (int i = 1; i < n + 1; i++) {
        if (vis[i]) continue;
        count++;
        dfs(i, g, vis);
    }
    cout << count << "\n";
    return 0;
}