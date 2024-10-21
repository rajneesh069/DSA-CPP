#include <bits/stdc++.h>
using namespace std;

int maxDepth(string s) {
    int j = 0;
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            j++;
            ans = max(ans, j);
        }

        if (s[i] == ')') {
            j--;
            ans = max(ans, j);
        }
    }
    return ans;
}

int main() {


    return 0;
}