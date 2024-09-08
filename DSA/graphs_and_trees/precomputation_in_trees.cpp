#include <bits/stdc++.h>
using namespace std;

void dfs(int v, int par, vector<vector<int>>& g, vector<int>& subtree_sum, vector<int>& even_ct) {
    // take action while going down the vertex
    subtree_sum[v] += v;
    if (v % 2 == 0) even_ct[v]++;
    for (int child : g[v]) {
        if (child == par) continue;
    // take action while going down the child
        dfs(child, v, g, subtree_sum, even_ct);
        subtree_sum[v] += subtree_sum[child];
        even_ct[v] += even_ct[child];
    // take action while coming up from the child
    }
    // take action while coming up from the vertex
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>>g(n + 1);

    for (int i = 1; i <= n - 1; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<int> subtree_sum(n + 1);
    vector<int> even_ct(n + 1);
    dfs(1, 0, g, subtree_sum, even_ct);
    for (int i = 1; i <= n; i++) {
        cout << subtree_sum[i] << " " << even_ct[i] << "\n";
    }
    return 0;
}