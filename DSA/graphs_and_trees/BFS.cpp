#include <bits/stdc++.h>
using namespace std;


void bfs(int source, vector<vector<int>>& g, vector<int>& b, vector<bool>& vis, int n) {
    queue<int>q;
    q.push(1);
    b.push_back(1);
    vis[1] = true;
    vector<int>level(n + 1, 0);
    while (!q.empty()) {
        int current_node = q.front();
        q.pop();
        b.push_back(current_node);
        for (int child : g[current_node]) {
            if (vis[child]) continue;
            q.push(child);
            vis[child] = true;
            level[child] = level[current_node] + 1;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << b[i] << ", level[" << b[i] << "]: " << level[i] << "\n";
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

    vector<bool>vis(n + 1, 0);
    vector<int>b;
    bfs(1, g, b, vis, n);

    return 0;
}