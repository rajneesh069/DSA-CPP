#include <bits/stdc++.h>
using namespace std;


class Solution {
private:
    void permutations(int j, vector<int>& v, vector<int>& ds, int f[], vector<vector<int>>& ans) {
        if (ds.size() == v.size()) {
            ans.push_back(ds);
            return;
        }

        for (int i = 0; i < v.size(); i++) {
            if (i > 0 && v[i] == v[i - 1] && f[i - 1] == 0) {
                continue;
            }
            if (f[i] != 1) {
                f[i] = 1;
                ds.push_back(v[i]);
                permutations(i + 1, v, ds, f, ans);
                ds.pop_back();
                f[i] = 0;
            }
        }

    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> ds;
        int f[nums.size()];
        for (int i = 0; i < nums.size();i++) { f[i] = 0; }
        permutations(0, nums, ds, f, ans);
        return ans;
    }
};