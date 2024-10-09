#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    // adjacency list : O(V+E)
    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt;
        graph[v1].push_back({ v2, wt });
        graph[v2].push_back({ v1, wt });
    }

    // N = 10^5, M<= 10^7

    for (const auto& row : graph) {
        for (const auto& el : row) {
            cout << "{node: " << el.first << " wt:" << el.second << "}, ";
        }
        cout << "\n";
    }

    return 0;
}