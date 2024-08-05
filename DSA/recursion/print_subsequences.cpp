#include <bits/stdc++.h>
using namespace std;

void print_subsequences(vector<vector<int>>& ans, vector<int>& current, int arr[], int n, int i) {
    if (i >= n) {
        ans.push_back(current);
        return;
    }

    current.push_back(arr[i]);
    print_subsequences(ans, current, arr, n, i + 1);
    current.pop_back();

    print_subsequences(ans, current, arr, n, i + 1);


}

int main() {
    int n = 3;
    int arr[n] = { 1,2,3 };
    vector<vector<int>> ans;
    vector<int> current;
    print_subsequences(ans, current, arr, n, 0);
    for (auto it : ans) {
        for (auto el : it) {
            cout << el << " ";
        }
        cout << endl;
    }

    return 0;
}