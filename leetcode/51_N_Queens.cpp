#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool is_possible(int row, int col, vector<int>& ds) {
        int n = ds.size();
        for (int i = 0; i < n; i++) {
            // row check 
            if (ds[i] == row) return false;

            //diagonal check
            if (abs(i - col) == abs(ds[i] - row)) return false;

        }

        return true;
    }

    void fn(int col, vector<int>& ds, vector<vector<string>>& ans, int& n) {

        if (col == n) {
            vector<string> temp;
            for (int c = 0; c < n; c++) {
                int index = n - 1 - ds[c];
                string temp_str = "";
                for (int i = 0; i < n; i++) {
                    if (i == index) {
                        temp_str.push_back('Q');
                    } else {
                        temp_str.push_back('.');
                    }
                }
                temp.push_back(temp_str);
            }

            ans.push_back(temp);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (is_possible(row, col, ds)) {
                ds.push_back(row);
                fn(col + 1, ds, ans, n);
                ds.pop_back();
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<int> ds;
        fn(0, ds, ans, n);
        return ans;
    }
};

int main() {


    return 0;
}