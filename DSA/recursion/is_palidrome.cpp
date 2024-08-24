#include <bits/stdc++.h>
using namespace std;

bool is_palindrome(string s, int i = 0) {
    if (i >= s.size() / 2) {
        return true;
    }

    return s[i] == s[s.size() - i - 1] && is_palindrome(s, i + 1);
}

int main() {

    string s = "ABBA";
    cout << is_palindrome(s) << endl;

    return 0;
}