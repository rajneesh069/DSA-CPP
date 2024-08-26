#include <bits/stdc++.h>
using namespace std;

void f(int ind, int n, vector<int>& v, vector<int>& current) {
    // Include the current subset in the output immediately
    for (auto& it : current) {
        cout << it << " ";
    }
    cout << "\n";

    // Explore further elements starting from the current index
    for (int i = ind; i < n; i++) {
        if (i > ind && v[i] == v[i - 1]) {
            continue;  // Skip duplicates
        }
        current.push_back(v[i]);
        f(i + 1, n, v, current);
        current.pop_back();
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    vector<int> current;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());  // Sort to handle duplicates
    f(0, n, v, current);

    return 0;
}
