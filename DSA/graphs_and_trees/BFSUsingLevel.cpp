#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 10;
//0-1 BFS for shortest path
// We use level array because we want to reduce the level upto 0, hence a node could be
// processed twice.
int bfs(vector<vector<pair<int, int>>>& graph, vector<int>& level, int n) {
    deque<int> q;
    q.push_back(1);
    level[1] = 0;
    while (!q.empty()) {
        int cur_v = q.front();
        q.pop_front();
        for (auto child : graph[cur_v]) {
            int child_v = child.first;
            int wt = child.second;
            if (level[cur_v] + wt < level[child_v]) { // 2 baar weight kam karenge, from 1 to 0.
                level[child_v] = level[cur_v] + wt;
                if (wt == 0) {
                    q.push_front(child_v);
                }
                else {
                    q.push_back(child_v);
                }
            }
        }

    }
    return level[n] == INF ? -1 : level[n];
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n + 1);
    vector<int> level(n + 1, INF);
    while (m--) {
        int x, y;
        cin >> x >> y;
        if (x == y) continue;
        graph[x].push_back({ y,0 });
        graph[y].push_back({ x,1 }); // our edge
    }

    cout << bfs(graph, level, n);

    return 0;
}