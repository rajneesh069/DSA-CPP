#include <bits/stdc++.h>
using namespace std;

int jump_with_k_steps(int n, int k, vector<int>& arr) {
    if (n == 0) return 0;
    int min_steps = INT_MAX;
    for (int i = 1; i <= k; i++) {
        if (n - i >= 0) {
            int jump = jump_with_k_steps(n - i, k, arr);
            min_steps = (min_steps, jump);
        }
    }
    return min_steps;
}

int jump_with_k_steps_memoized(int i, int k, vector<int>& arr, vector<int>& dp) {
    if (i == 0) return 0;
    if (dp[i] != -1) return dp[i];
    int min_steps = INT_MAX;
    for (int j = 1; j <= k; j++) {
        if (i - j >= 0) {
            int jump = jump_with_k_steps_memoized(i - j, k, arr, dp) + abs(arr[i - j] - arr[i]);
            min_steps = (min_steps, jump);
        }
    }
    return dp[i] = min_steps;
}

int jump_with_k_steps_tabulated(int n, int k, vector<int>& arr, vector<int>& dp) {
    if (n == 0) return 0;
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        int min_steps = INT_MAX;
        for (int j = 1; j <= k; j++) {
            if (i - j >= 0) {
                int jump = dp[i - j] + abs(arr[i - j] - arr[i]);
                min_steps = min(jump, min_steps);
            }
        }
        dp[i] = min_steps;
    }

    return dp[n];
}


int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> dp(n + 1, -1);
    cout << jump_with_k_steps_tabulated(n - 1, k, arr, dp);
    return 0;
}