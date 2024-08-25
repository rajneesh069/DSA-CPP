#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void solve(int i, vector<vector<int>>& ans, vector<int>& current,
        vector<int>& candidates, int target) {
        if (i == candidates.size()) {
            if (target == 0) {
                ans.push_back(current);
            }
            return;
        }

        if (candidates[i] <= target) {
            current.push_back(candidates[i]);
            solve(i, ans, current, candidates, target - candidates[i]);
            current.pop_back();
        }
        solve(i + 1, ans, current, candidates, target);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> current;
        solve(0, ans, current, candidates, target);
        return ans;
    }
};