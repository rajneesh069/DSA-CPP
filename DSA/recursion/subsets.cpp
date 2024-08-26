#include <bits/stdc++.h>
using namespace std;

void f(int ind, int sum, int n, vector<int>& v, vector<int>& current) {
    if (ind >= n) {
        if (current.size() == 0) cout << "{}";
        for (auto& it : current) {
            cout << it << " ";
        }
        cout << "\n" << "sum: " << sum << "\n \n";
        return;
    }

    current.push_back(v[ind]);
    f(ind + 1, sum + v[ind], n, v, current);
    current.pop_back();

    f(ind + 1, sum, n, v, current);
}

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    vector<int> current;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    f(0, 0, n, v, current);

    return 0;
}