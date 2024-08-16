#include <bits/stdc++.h>
using namespace std;


int main() {
    string string1, string2;
    cin >> string1 >> string2;
    vector<int> f(26);
    string str;
    for (auto c : string2) {
        f[c - 'a']++;
    }
    for (auto c : string1) {
        if (f[c - 'a'] > 0) {
            f[c - 'a']--;
        }
        else {
            str.push_back(c);
        }
    }
    for (auto& el : str)
    {
        cout << el;
    }

    return 0;
}
