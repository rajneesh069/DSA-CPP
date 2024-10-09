#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> v(n + 1, 0);
    int t;
    cin >> t;
    vector<vector<long long>> q(t, vector<long long>(3));
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> q[i][j];
        }
    }

    for (int i = 0; i < t; i++) {
        int a = q[i][0], b = q[i][1], k = q[i][2];
        v[a] += k;
        if (b + 1 <= n) v[b + 1] -= k;
    }

    for (int i = 1; i <= n; i++) {
        v[i] += v[i - 1];
    }

    long long max_el = v[1];
    for (int i = 2; i <= n; i++) {
        if (max_el < v[i]) {
            max_el = v[i];
        }
    }

    cout << max_el;
    return 0;
}
