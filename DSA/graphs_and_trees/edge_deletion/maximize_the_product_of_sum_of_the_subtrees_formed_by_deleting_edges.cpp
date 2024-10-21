#include <bits/stdc++.h>
using namespace std;

void dfs(int v, int par, vector<vector<int>>& g, vector<int>& subtree_sum) {
    subtree_sum[v] = v;
    for (int c : g[v]) {
        if (c == par) continue;
        dfs(c, v, g, subtree_sum);
        subtree_sum[v] += subtree_sum[c];
    }
}


int main() {
    int n;
    cin >> n;
    vector<vector<int>>g(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int x, y; cin >> x >> y;
        g[y].push_back(x);
        g[x].push_back(y);
    }
    vector<int>subtree_sum(n + 1, 0);
    dfs(1, -1, g, subtree_sum);

    // delete edge: Delete the top edge of the node
    long long ans = 1;
    for (int i = 2; i <= n; i++) {
        int part_1 = subtree_sum[i];
        int part_2 = subtree_sum[1] - subtree_sum[i];
        ans = max(ans, part_1 * 1LL * part_2);
    }
    cout << ans << "\n";
    return 0;
}