#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    // adjacency list : O(V+E)
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    // N = 10^5, M<= 10^7

    for (const auto& row : graph) {
        for (const auto& el : row) {
            cout << el << " ";
        }
        cout << "\n";
    }

    return 0;
}