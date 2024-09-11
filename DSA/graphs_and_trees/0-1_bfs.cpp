#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 10;

int bfs(vector<vector<pair<int, int>>>& g, vector<int>& lev, int n) {
    deque<int> q;
    q.push_back(1);
    lev[1] = 0;
    while (!q.empty()) {
        int cur_v = q.front();
        q.pop_front();
        for (auto child : g[cur_v]) {
            int child_v = child.first;
            int wt = child.second;
            if (lev[cur_v] + wt < lev[child_v]) {
                lev[child_v] = lev[cur_v] + 1;
            /* to process the node again even if it has been
            processed already, that's why no visited array as we need to process the path with
            wt = 0, that's why we used the level technique, it can be used in regular BFS too, by
            setting the level once and then skipping the nodes whose level isn't INF.
            */
                if (wt == 0) {
                    q.push_front(child_v);
                } else {
                    q.push_back(child_v);
                }
            }
        }
    }
    return lev[n] == INF ? -1 : lev[n]; // lev[n] because we need to check for the shortest path between 1 to N
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>>g(n + 1);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        if (x == y) continue; // do avoid self loops, i.e., edge between the same element
        g[x].push_back({ y,0 });
        g[y].push_back({ x,1 });
    }
    vector<int> lev(n + 1, INF);
    cout << bfs(g, lev, n) << " ";
    return 0;
}