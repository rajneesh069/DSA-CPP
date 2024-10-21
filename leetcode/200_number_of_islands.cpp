#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int i, int j, vector<vector<char>>& g, vector<vector<bool>>& vis) {
        if (i < 0 || j < 0 || i >= g.size() || j >= g[0].size() || g[i][j] == '0' || vis[i][j]) return;
        vis[i][j] = true;
        dfs(i + 1, j, g, vis);
        dfs(i - 1, j, g, vis);
        dfs(i, j + 1, g, vis);
        dfs(i, j - 1, g, vis);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>>vis(m, vector<bool>(n, false));
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    count++;
                    dfs(i, j, grid, vis);
                }
            }
        }

        return count;
    }

};

int main() {


    return 0;
}