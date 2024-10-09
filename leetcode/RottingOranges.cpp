#include <bits/stdc++.h>
using namespace std;

bool isValid(int x, int y, int n, int m) {
    return x >= 0 && y >= 0 && x < n && y < m;
}
int orangesRotting(vector<vector<int>>& grid) {
    vector<pair<int, int>> movements = {
    {1,0} , {-1,0}, {0,1}, {0,-1}
    };
    int n = grid.size(); int m = grid[0].size();
    queue<pair<int, int>> q;
    vector<vector<int>> lev(n, vector<int>(m, -1));
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == 2) {
                q.push({ i,j });
                lev[i][j] = 0;
                vis[i][j] = true;
            }
        }
    }

    int ans = 0;

    while (!q.empty()) {
        int v_x = q.front().first;
        int v_y = q.front().second;
        q.pop();
        for (auto movement : movements) {
            int child_x = v_x + movement.first;
            int child_y = v_y + movement.second;
            if (!isValid(child_x, child_y, n, m)) continue;
            if (vis[child_x][child_y]) continue;
            if (grid[child_x][child_y] == 0 || grid[child_x][child_y] == 2) continue;
            q.push({ child_x, child_y });
            lev[child_x][child_y] = lev[v_x][v_y] + 1;
            vis[child_x][child_y] = true;
            ans = max(ans, lev[child_x][child_y]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1 && !vis[i][j]) return -1;
        }
    }

    return ans;
}