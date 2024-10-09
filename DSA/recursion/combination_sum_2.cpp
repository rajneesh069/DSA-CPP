#include <bits/stdc++.h>
using namespace std;

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


int main() {
    int n, target;
    cin >> n, target;

    vector<int> v;
    vector<vector<int>> ans;
    vector<int> current;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end()); // sort the original array

    f(0, target, n, current, ans, v);

    return 0;
}