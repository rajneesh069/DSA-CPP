#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 10;

int getX(string s) {
    return s[0] - 'a';
}
int getY(string s) {
    return s[1] - '1';
}

int vis[8][8];
int lev[8][8];

vector<pair<int, int>> movements = {
    {1,2}, {-1,2},
    {2,1}, {2,-1},
    {-2,-1}, {-2,1},
    {1,-2}, {-1,-2}
};

bool isValid(int x, int y) {
    return x >= 0 && y >= 0 && x < 8 && y < 8;
}

int bfs(string src, string dest) {
    int srcX = getX(src);
    int srcY = getY(src);
    int destX = getX(dest);
    int destY = getY(dest);
    queue<pair<int, int>> q;
    q.push({ srcX, srcY });
    vis[srcX][srcY] = 1;

    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        int x = p.first;
        int y = p.second;
        for (auto movement : movements) {
            int childX = movement.first + x;
            int childY = movement.second + y;
            if (!isValid(childX, childY)) continue;
            if (vis[childX][childY]) continue;
            q.push({ childX, childY });
            lev[childX][childY] = lev[x][y] + 1;
            vis[childX][childY] = 1;
        }
        if (lev[destX][destY] != INF) break;
    }
    return lev[destX][destY];

}

void reset() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            lev[i][j] = INF;
            vis[i][j] = 0;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        reset();
        string s1, s2;
        cin >> s1 >> s2;
        cout << bfs(s1, s2);
    }

    return 0;
}