#include <bits/stdc++.h>
using namespace std;

/*
    Given 2D array of N*N integers. Given Q queries and in each query given
    a,b,c and d print sum of square represented by (a,b) as top left point and
    (c,d) as top bottom right point.

    Constraints:
    1<=N<=10^3
    1<=a[i][j]<=10^9
    1<=Q<=10^5
    1<=a,b,c,d<=N
*/

int main() {
    int n;
    cin >> n;
    vector<vector<int>>v(n + 1, vector<int>(n + 1, 0));
    vector<vector<long long>>pf(n + 1, vector<long long>(n + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> v[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            pf[i][j] = v[i][j] + pf[i - 1][j] + pf[i][j - 1] - pf[i - 1][j - 1];
        }
    }

    int q;
    cin >> q;
    while (q--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << pf[c][d] - pf[a - 1][d] - pf[c][b - 1] + pf[a - 1][b - 1] << endl;
    }


    return 0;
}