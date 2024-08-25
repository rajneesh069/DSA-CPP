#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int f(int target, vector<int>& v) {
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
        for (int i = 0;i < v.size();i++) {
            ans += f(target - v[i], v);
        }
        return dp[target] = ans;

    }

public:
    vector<int> dp;
    int combinationSum4(vector<int>& nums, int target) {
        dp.resize(1001, -1);
        return f(target, nums);
    }
};