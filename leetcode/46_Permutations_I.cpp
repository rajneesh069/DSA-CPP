#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void f(int ind, int n, int freq[], vector<int>& ds, vector<vector<int>>& ans, vector<int>& v) {
        if (ds.size() == n) {
            ans.push_back(ds);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (!freq[i]) {
                freq[i] = 1;
                ds.push_back(v[i]);
                f(i + 1, n, freq, ds, ans, v);
                ds.pop_back();
                freq[i] = 0;
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int n = nums.size();
        int freq[n];
        for (int i = 0; i < n; i++) freq[i] = 0;
        f(0, n, freq, ds, ans, nums);
        return ans;
    }
};