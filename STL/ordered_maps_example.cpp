#include <bits/stdc++.h>
using namespace std;


int main() {
    int N;
    cin >> N;
    map<string, int> m; // map of strings and its frequency
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        if (!s.empty()) m[s]++;
    }
    for (auto& el : m) {
        cout << el.first << " " << el.second << endl;
    }

    return 0;
}