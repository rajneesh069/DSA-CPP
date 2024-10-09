#include <bits/stdc++.h>
using namespace std;
/*
Given an array 'a' of N integers. Given Q queries and in each
query given a number X, print the count of that number in array.

Constraints:
1<=N<=10^5
1<=a[i]<=10^7
1<=Q<=10^5
 */

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int q;
    cin >> q;
    // while (q--) // O(q*n) == O(10^10) => this won't run in one second
    // {
    //     int x;
    //     cin >> x;
    //     int ct = 0;
    //     for (int i = 0; i < n; i++) {
    //         if (a[i] == x) {
    //             ct++;
    //         }
    //     }
    //     cout << ct << endl;
    // }
    vector<int> freq(1e7 + 10);
    for (int i = 0; i < n; i++) { // O(n)
        freq[a[i]]++;
    }

    while (q--) { // O(q)
        int x;
        cin >> x;
        cout << freq[x] << endl;
    }

    // Total time complexity = O(n+q)

    return 0;
}