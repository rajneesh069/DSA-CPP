#include <bits/stdc++.h>
using namespace std;

/*
    Matrix Problems in Graph
    - Assume all 1's to be the nodes of a graph and that way we'll have components.
    -  DFS needs to be done in either 4 directions or 8(including diagonals).

*/

void dfs(int i, int j, int initialColor, int newColor, vector<vector<int>>& image) {
    int n = image.size();
    int m = image[0].size();
    if (i < 0 || j < 0) return;
    if (i >= n || j >= m) return;
    if (image[i][j] != initialColor) return;

    image[i][j] = newColor;

    dfs(i - 1, j, initialColor, newColor, image);
    dfs(i + 1, j, initialColor, newColor, image);
    dfs(i, j - 1, initialColor, newColor, image);
    dfs(i, j + 1, initialColor, newColor, image);
}


vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int initialColor = image[sr][sc];
    if (initialColor != newColor)
        dfs(sr, sc, initialColor, newColor, image);
    return image;
}


int main() {
    // Flood fill


    return 0;
}