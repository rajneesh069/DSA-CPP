#include <bits/stdc++.h>
using namespace std;

bool is_valid_pos(int x, int y) {
    return x >= 0 && y >= 0 && x < 8 && y < 8;
}

int getX(string s) {
    return s[0] - 'a';
}

int getY(string s) {
    return s[1] - '1';
}

vector<pair<int, int>> movements = {
    {2, 1},  {2, -1},
    {-2, 1}, {-2, -1},
    {1, 2},  {-1, 2},
    {-1, -2},{1, -2}
};

int bfs(string src, string dest, vector<vector<bool>>& vis, vector<vector<int>>& level) {
    int srcX = getX(src);
    int srcY = getY(src);
    int destX = getX(dest);
    int destY = getY(dest);
    
    queue<pair<int, int>> q;
    q.push({srcX, srcY});
    vis[srcX][srcY] = true;
    
    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();

        int parX = curr.first;
        int parY = curr.second;

        for (auto movement : movements) {
            int childX = parX + movement.first;
            int childY = parY + movement.second;
            if (!is_valid_pos(childX, childY)) continue;
            if (!vis[childX][childY]) {
                q.push({childX, childY});
                level[childX][childY] = level[parX][parY] + 1;
                vis[childX][childY] = true;
            }
        }
    }

    return level[destX][destY];
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        vector<vector<bool>> vis(8, vector<bool>(8, false)); // Reinitialize inside the loop
        vector<vector<int>> level(8, vector<int>(8, 0));     // Reinitialize inside the loop
        
        string src, dest;
        cin >> src >> dest;
        
        cout << bfs(src, dest, vis, level) << endl;
    }

    return 0;
}
