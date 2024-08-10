#include <bits/stdc++.h>
using namespace std;

int bfs(vector<vector<pair<int, int>>> graph, vector<int> level, int n) {

}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n);
    vector<int> level(n, INFINITY);
    while (m--) {
        int x, y;
        cin >> x >> y;
        if (x == y) continue;
        graph[x].push_back({ y,0 });
        graph[y].push_back({ x,1 }); // our edge
    }


    return 0;
}