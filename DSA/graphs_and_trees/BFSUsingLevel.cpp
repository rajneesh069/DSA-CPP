#include <bits/stdc++.h>
using namespace std;

// 1 based indexing graph

/* Inputs
4 4
1 2
2 3
2 4
3 4
*/
const int INF = 1e9 + 10;

int bfs(vector<vector<int>>& graph, vector<int>& level, int src) {
    queue<int> q;
    q.push(src);
    level[src] = 0;
    while (!q.empty()) {
        int cur_v = q.front();
        q.pop();
        for (auto child : graph[cur_v]) {
            if (level[child] != INF) continue;
            q.push(child);
            level[child] = level[cur_v] + 1;
        }
    }
    return 0;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    vector<int> level(n + 1, INF);
    while (m--) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    bfs(graph, level, 1);
    for (int i = 1; i < level.size(); i++) {
        cout << level[i] << " ";
    }
    return 0;
}