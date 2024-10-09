#include <bits/stdc++.h>
using namespace std;

int main() {
    set<string> s;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        s.insert(str);
    }
    for (auto& el : s) {
        cout << el << endl;
    }

    return 0;
}