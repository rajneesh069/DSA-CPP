#include <bits/stdc++.h>
using namespace std;

// taking the same element multiple times without the NOT taking case
int f(int target, vector<int>& v, vector<int>& dp) {
    if (target < 0) {
        return 0;
    }
    if (target == 0) {
        return 1;
    }
    if (dp[target] != -1) {
        return dp[target];
    }
    int ans = 0;
    for (int i = 0;i < v.size();i++) { // always taking as all combinations are valid
        ans += f(target - v[i], v, dp);
    }
    return dp[target] = ans;

}

int main() {
    int target, n;
    cin >> n >> target;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vector<int> dp;
    dp.resize(1001, -1);
    cout << f(target, nums, dp);
    return 0;
}