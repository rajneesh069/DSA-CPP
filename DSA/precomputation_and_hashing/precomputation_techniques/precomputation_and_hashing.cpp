#include <bits/stdc++.h>
using namespace std;

// prefix sum and hashing
int main() {
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        vector<vector<int>>v(s.size() + 1, vector<int>(26, 0));
        for (int i = 0; i < n; i++) {
            v[i + 1][s[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            for (int j = 1; j <= n; j++) {
                v[j][i] += v[j - 1][i];
            }
        }
        while (q--)
        {
            int l, r;
            cin >> l >> r;
            int oddCt = 0;
            for (int i = 0; i < 26; i++) {
                int charCt = v[r][i] - v[l - 1][i];
                if (charCt % 2 != 0) oddCt++;
            }
            if (oddCt > 1) cout << "NO\n";
            else cout << "YES\n";
        }

    }


    return 0;
}