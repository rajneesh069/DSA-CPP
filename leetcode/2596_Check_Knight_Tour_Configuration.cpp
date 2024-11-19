#include <bits/stdc++.h>
using namespace std;

vector <pair<int, int>> movements =
{
    {-2, 1}, {-2, -1}, {-1, 2}, {-1, -2},
    {2, -1}, {2, 1}, {1, -2}, {1,2}
};
class Solution {
private:
    bool is_valid(int x, int y, int n) {
        return x >= 0 && y >= 0 && x < n && y < n;
    }
    bool fn(vector<vector<int>>& grid, int n, int step, int row, int col) {
        if (step == (n * n) - 1) {
            return true;
        }

        for (auto& p : movements) {
            int x = row + p.first, y = col + p.second;
            if (!is_valid(x, y, n)) continue;
            int pos = grid[x][y];
            if (pos == step + 1) {
                return fn(grid, n, step + 1, x, y);
            }
        }

        return false;
    }
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int step = 0, row = 0, col = 0;
        if (grid[0][0] != 0) return false;
        return fn(grid, n, step, row, col);
    }
};

int main() {


    return 0;
}