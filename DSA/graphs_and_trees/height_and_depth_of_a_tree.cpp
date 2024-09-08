#include <bits/stdc++.h>
using namespace std;

void dfs(int v, int par, vector<vector<int>>& g, vector<int>& depth, vector<int>& height) {

    // going down into the vertex
    for (int child : g[v]) {
        // going down into the child
        if (child == par) continue;
        depth[child] = depth[v] + 1;
        dfs(child, v, g, depth, height);
        height[v] = max(height[child] + 1, height[v]);
        // coming up from the child
    }
    // coming up from the vertex
}


int main() {
    int n;
    cin >> n;
    vector<vector<int>>graph(n + 1);

    vector<int> depth(n + 1, 0);
    vector<int> height(n + 1);


    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    dfs(1, 0, graph, depth, height);

    for (int i = 1; i <= n; i++) {
        cout << depth[i] << " " << height[i] << "\n";
    }


    return 0;
}