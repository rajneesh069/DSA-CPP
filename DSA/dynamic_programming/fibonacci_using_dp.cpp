#include <bits/stdc++.h>
using namespace std;

// recursive way
int fibo_recursive(int n) {
    if (n < 2) {
        return n;
    }
    return fibo_recursive(n - 1) + fibo_recursive(n - 2);
}

// memoization: Time Complexity -> O(N), Space Complexity -> O(2N) = Stack Space + Array Space
int f_memo(int n, vector<int>& dp) {
    if (n <= 1) {
        return n;
    }
    if (dp[n] != -1) return dp[n];
    return dp[n] = f_memo(n - 1, dp) + f_memo(n - 2, dp);
}

//tabulation: Time Complexity -> O(N), Space Complexity -> O(N) = Array Space
int f_tabulated(int n, vector<int>& dp) {
    dp[0] = 0; dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

// space optimization: Time Complexity -> O(N), Space Complexity -> O(1)
int f_space_optimized(int n) {
    int prev2 = 0, prev = 1;
    if (n < 2) return n;
    for (int i = 2; i <= n; i++) {
        int curi = prev2 + prev;
        prev2 = prev;
        prev = curi;
    }
    return prev;
}

int main() {
    // cout << fibo_recursive(4) << "\n";
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    // cout << f_memo(n, dp) << "\n";
    // cout << f_tabulated(n, dp);
    cout << f_space_optimized(n) << "\n";

    return 0;
}
