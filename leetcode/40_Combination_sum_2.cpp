#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void f(int ind, int target, int& n, vector<int>& ds,
        vector<vector<int>>& ans, vector<int>& v) {
        if (target == 0) {
            ans.push_back(ds);
            return;
        }

        for (int i = ind; i < n; i++) {
            if (i > ind && v[i] == v[i - 1])
                continue;
            if (v[i] > target)
                break;
            ds.push_back(v[i]);
            f(i + 1, target - v[i], n, ds, ans, v);
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        int n = candidates.size();
        f(0, target, n, ds, ans, candidates);
        return ans;
    }
};