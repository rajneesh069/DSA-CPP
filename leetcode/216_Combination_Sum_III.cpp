#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void fn(vector<int>& v, int target, int k, int i, vector<int>& ds, vector<vector<int>>& ans) {
        if (ds.size() == k) {
            if (target == 0) {
                ans.push_back(ds);
            }
            return;
        }

        if (i >= v.size()) return;

        ds.push_back(v[i]);
        target -= v[i];
        fn(v, target, k, i + 1, ds, ans);
        target += v[i];
        ds.pop_back();

        fn(v, target, k, i + 1, ds, ans);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v;
        vector<int> ds;
        vector<vector<int>> ans;
        for (int i = 0; i < 9; i++) {
            v.push_back(i + 1);
        }
        fn(v, n, k, 0, ds, ans);
        return ans;
    }
};


int main() {


    return 0;
}