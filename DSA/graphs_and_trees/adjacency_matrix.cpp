#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    // adjacency matrix -> too much space complexity(O(N^2))
    vector<vector<int>>graph(n + 1, vector<int>(n + 1, 0)); // initialized a 2D vector
    for (int i = 0; i < m; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1][v2] = 1;
        graph[v2][v1] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}