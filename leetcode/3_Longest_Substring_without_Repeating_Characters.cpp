#include <bits/stdc++.h>
using namespace std;


int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int>m(256, -1);
    int l = 0, r = 0;
    int max_length = 0;
    while (r < n) {
        int length = 0;
        if (m[s[r]] != -1) {
            if (m[s[r]] >= l) {
                l = m[s[r]] + 1;

            }
        }
        m[s[r]] = r;
        length = r - l + 1;
        max_length = max(max_length, length);
        r++;
    }
    cout << "max length: " << max_length;
    return 0;
}