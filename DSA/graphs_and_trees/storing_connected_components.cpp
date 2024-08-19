#include <bits/stdc++.h>
using namespace std;


void dfs(int vertex, vector<int> g[], vector<bool>& vis, vector<int>& ccc) {
    // take action on vertex after entering the vertex
    vis[vertex] = true;
    ccc.push_back(vertex);
    for (int child : g[vertex]) {
        // take action on child before entering the child node(haven't called dfs yet)
        if (vis[child]) continue;
        dfs(child, g, vis, ccc);
        // take action on child after exiting the child node(called dfs on child)
    }
    // take action on vertex before exiting the vertex
}



int main() {
    int n, m;
    cin >> n >> m;
    vector<int> g[n + 1];
    vector<bool>vis(n + 1, false);
    vector<vector<int>> cc;
    for (int i = 0; i < m; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    int count = 0;
    for (int i = 1; i < n + 1; i++) {
        if (vis[i]) continue;
        vector<int> ccc; // initialize a new current connected component vector
        count++;
        dfs(i, g, vis, ccc);
        cc.push_back(ccc); // push it back after the dfs completes for each connected component
    }

    for (auto& row : cc) {
        for (auto& el : row) {
            cout << el << " ";
        }
        cout << "\n";
    }

    return 0;
}