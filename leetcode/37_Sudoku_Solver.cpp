#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<char>> vvc;

class Solution {
private:
    bool is_possible(vvc& board, int i, int j, int n) {
        for (int k = 0; k < 9; k++) {
            if (board[k][j] == (char)(n + '0'))
                return false;
        }

        for (int k = 0; k < 9; k++) {
            if (board[i][k] == (char)(n + '0'))
                return false;
        }

        int sr = 3 * (i / 3), sc = 3 * (j / 3), er = sr + 2, ec = sc + 2;

        for (int k = sr; k <= er; k++) {
            for (int l = sc; l <= ec; l++) {
                if (board[k][l] == (char)(n + '0'))
                    return false;
            }
        }

        return true;
    }

    bool fn(vector<vector<char>>& board, int i, int j) {
        if (j == 9) {
            j = 0;
            i++;
        }

        if (i == 9 && j == 0) {
            return true;
        }

        if (board[i][j] != '.') {
            return fn(board, i, j + 1);
        }

        for (int n = 1; n < 10; n++) {
            if (is_possible(board, i, j, n)) {
                board[i][j] = (char)(n + '0');
                if (fn(board, i, j + 1))
                    return true;
                board[i][j] = '.';
            }
        }

        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) { fn(board, 0, 0); }
};

int main() {


    return 0;
}