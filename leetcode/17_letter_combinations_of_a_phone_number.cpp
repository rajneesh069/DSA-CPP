#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void fn(string& s, int i, string& ds, vector<string>& ans, unordered_map<int, vector<char>>& m) {
        if (i >= s.size()) {
            ans.push_back(ds);
            return;
        }

        int digit = s[i] - '0';

        for (int j = 0; j < m[digit].size(); j++) {
            ds.push_back(m[digit][j]);
            fn(s, i + 1, ds, ans, m);
            ds.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string& s) {
        if (s.size() == 0) return {};
        unordered_map<int, vector<char>> m;
        m[2] = { 'a', 'b', 'c' };
        m[3] = { 'd', 'e', 'f' };
        m[4] = { 'g', 'h', 'i' };
        m[5] = { 'j', 'k', 'l' };
        m[6] = { 'm', 'n', 'o' };
        m[7] = { 'p', 'q', 'r', 's' };
        m[8] = { 't', 'u', 'v' };
        m[9] = { 'w', 'x', 'y', 'z' };

        vector<string> ans;
        string ds;
        fn(s, 0, ds, ans, m);

        return ans;
    }
};

int main() {


    return 0;
}