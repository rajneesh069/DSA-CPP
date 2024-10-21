#include <bits/stdc++.h>
using namespace std;

string removeOuterParentheses(string s) {
    string ans = "";
    int j = 0;
    for (int i = 0; i < s.size(); i++) {

        if (s[i] == '(') {
            j++;
            if (j > 1) {
                ans.push_back(s[i]);
            }
        }

        if (s[i] == ')') {
            if (j > 1) {
                ans.push_back(s[i]);
            }
            j--;
        }
    }

    return ans;
}

int main() {


    return 0;
}