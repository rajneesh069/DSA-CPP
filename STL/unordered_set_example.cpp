#include <bits/stdc++.h>
using namespace std;
// Given N strings and Q queries, print yes if the string is present in the query. N <= 10^5, string.length=100000

int main() {
    unordered_set<string> us;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        us.insert(s);
    }
    int Q;
    cin >> Q;
    while (Q--)
    {
        string s;
        cin >> s;
        auto it = us.find(s);
        if (it != us.end()) {
            cout << "yes" << endl;
            continue;
        }
        cout << "no" << endl;

    }

    return 0;
}