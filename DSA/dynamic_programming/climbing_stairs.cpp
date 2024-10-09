#include <bits/stdc++.h>
using namespace std;

// this is the recursive way(btw it looks like fibonacci)
int climb_stairs(int i) { // we'll jump down
    if (i == 0) return 1;
    // however, what if i=1, then we'll need to handle the edge case of i = 1
    if (i == 1) return 1;
    int left = climb_stairs(i - 1);
    int right = climb_stairs(i - 2);

    return left + right;

}

// let's memoize it
int f(int i, vector<int>& dp) {
    if (i == 0) return 1;
    if (i == 1) return 1;
    if (dp[i] != -1) return dp[i];
    int left = f(i - 1, dp);
    int right = f(i - 2, dp);

    return dp[i] = left + right;
}

// let's tabulate this
int t(int n, vector<int>& dp) {
    if (n == 0) return 1;
    if (n == 1) return 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
}

//let's do space optimization
int s(int n) {
    if (n == 0) return 1;
    if (n == 1) return 1;
    int prev = 1, prev2 = 1;
    for (int i = 0; i <= n; i++) {
        int curi = prev2 + prev;
        prev2 = prev;
        prev = curi;
    }

    return prev;
}


int main() {
    // Represent the problem in terms of indices.
    // We'll consider the stairs to be indices from 0 to n.
    // Then either we can jump 1 step or 2 steps -> the things we can do with the index.

    return 0;
}