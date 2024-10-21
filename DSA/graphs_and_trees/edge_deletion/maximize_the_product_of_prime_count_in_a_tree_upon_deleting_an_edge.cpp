#include <bits/stdc++.h>
using namespace std;

void dfs(int v, int par, vector<vector<int>>& g, vector<int>& subtree_prime_count, vector<bool>& isPrime) {
    if (isPrime[v])
        subtree_prime_count[v]++;
    for (int c : g[v]) {
        if (c == par) continue;
        dfs(c, v, g, subtree_prime_count, isPrime);
        subtree_prime_count[v] += subtree_prime_count[c];
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
    vector<int>subtree_prime_count(n + 1, 0);
    vector<bool>isPrime(n + 1, true);

    isPrime[1] = isPrime[0] = 0;
    for (int i = 2; i < n + 1; i++) {
        if (isPrime[i]) {
            for (int j = 2 * i; j < n + 1; j += i) {
                isPrime[j] = 0;
            }
        }
    }

    dfs(1, -1, g, subtree_prime_count, isPrime);

    for (int i = 1; i <= n; i++) {
        cout << subtree_prime_count[i] << "\n";
    }

    // delete edge: Delete the top edge of the node
    long long ans = 1;
    for (int i = 2; i <= n; i++) {
        int part_1 = subtree_prime_count[i];
        int part_2 = subtree_prime_count[1] - subtree_prime_count[i];
        ans = max(ans, part_1 * 1LL * part_2);
    }
    cout << "ans: " << ans << "\n";
    return 0;
}