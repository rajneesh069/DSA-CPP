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

    void fn(int col, vector<int>& ds, int& n, int& ct) {

        if (col == n) {
            ct++;
            return;
        }

        for (int row = 0; row < n; row++) {
            if (is_possible(row, col, ds)) {
                ds.push_back(row);
                fn(col + 1, ds, n, ct);
                ds.pop_back();
            }
        }
    }
public:
    int totalNQueens(int n) {
        int ct = 0;
        vector<int> ds;
        fn(0, ds, n, ct);
        return ct;
    }
};

int main() {


    return 0;
}