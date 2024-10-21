#include <bits/stdc++.h>
using namespace std;

int romanToInt(string s) {
    unordered_map<char, int> m;
    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;

    int ans = 0;

    for (int i = s.size() - 1; i >= 0; i--) {
        if (m[s[i]] == 1) {
            ans++;
        }

        if (m[s[i]] == 5) {
            if (i > 0 && m[s[i - 1]] < 5) {
                i--;
                ans += 4;
            } else {
                ans += m[s[i]];
            }
        }

        if (m[s[i]] == 10) {
            if (i > 0 && m[s[i - 1]] < 10) {
                i--;
                ans += 9;
            } else {
                ans += m[s[i]];
            }
        }

        if (m[s[i]] == 50) {
            if (i > 0 && m[s[i - 1]] < 50) {
                i--;
                ans += 40;
            } else {
                ans += m[s[i]];
            }
        }

        if (m[s[i]] == 100) {
            if (i > 0 && m[s[i - 1]] < 100) {
                i--;
                ans += 90;
            } else {
                ans += m[s[i]];
            }
        }

        if (m[s[i]] == 500) {
            if (i > 0 && m[s[i - 1]] < 500) {
                i--;
                ans += 400;
            } else {
                ans += m[s[i]];
            }
        }

        if (m[s[i]] == 1000) {
            if (i > 0 && m[s[i - 1]] < 1000) {
                i--;
                ans += 900;
            } else {
                ans += m[s[i]];
            }
        }
    }

    return ans;
}

int main() {


    return 0;
}