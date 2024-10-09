#include <bits/stdc++.h>
using namespace std;
/*
Given an array 'a' of N integers. Given Q queries and in each query given L
and R, print sum of the array elements from L to R (both incluive).

Constraints:
1<=N<=10^5
1<=a[i]<=10^9
1<=Q<=10^5
1<=L,R<=N
*/

// Use 1-based indexing in case of prefix sum
int main() {
    int N;
    cin >> N;
    vector<int> a(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    // pre-compute the prefix-sum in a pf vector, declare it vector<long long>
    // because of the order of elements of the vector 'a'

    // computing the prefix sum
    vector<long long> pf(N + 1); // 'long long' because of the nature of the elements of vector 'a'
    pf[1] = a[0];
    for (int i = 2; i <= N; i++) {
        pf[i] = pf[i - 1] + a[i];
    }

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << pf[r] - pf[l - 1] << endl;
    }


    return 0;
}