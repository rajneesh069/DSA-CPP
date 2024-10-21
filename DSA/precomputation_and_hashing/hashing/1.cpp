#include <bits/stdc++.h>
using namespace std;
/*
Given T testcases and in each test case a number N. Print its factorial for each
test case % M, where M = 1e9^9+7.

    Contraints:
    1<=N<=10^5
    1<=T<=10^5
 */

const int M = 1e9 + 7;

int main() {
    const int N = 1e5 + 10;
    long long fact[N];
    fact[0] = fact[1] = 1;
    for (int i = 2; i <= N; i++) {
        fact[i] = fact[i - 1] * i;
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << fact[n] << endl;
    }



    return 0;
}