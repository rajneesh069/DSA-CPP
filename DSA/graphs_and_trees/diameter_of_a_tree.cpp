#include <bits/stdc++.h>
using namespace std;

void dfs(int v, int p, vector<int>& d, vector<vector<int>>& g) {
    for (int c : g[v]) {
        if (c == p) continue;
        d[c] = d[v] + 1;
        dfs(c, v, d, g);
    }
}

void reset(vector<int>& d) {
    for (int i = 0; i < d.size(); i++) {
        d[i] = 0;
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>>g(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int x, y; cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<int>d(n + 1, 0);

    dfs(1, -1, d, g);

    int max_depth_node = -1;
    int max_depth = -1;
    for (int i = 1; i <= n; i++) {
        if (max_depth <= d[i]) {
            max_depth = d[i];
            max_depth_node = i;
        }
    }
    cout << max_depth_node << " " << max_depth << "\n";

    reset(d);

    dfs(12, 0, d, g);

    int max_depth_node_1 = -1;
    int max_depth_1 = -1;
    for (int i = 1; i <= n; i++) {
        if (max_depth_1 <= d[i]) {
            max_depth_1 = d[i];
            max_depth_node_1 = i;
        }
    }

    cout << max_depth_node_1 << " " << max_depth_1 << "\n";
    int diameter = max_depth_1;
    cout << diameter;
    // max_depth_node and max_depth_node_1 are the two ends of the diameter.
    return 0;
}