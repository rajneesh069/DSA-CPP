#include <bits/stdc++.h>
using namespace std;
// 1 0 5 2 => 0 1 2 5
// 1 0 5
void fn(vector<int>& v, int el) {
    if (v.empty() || v.back() <= el) {
        v.push_back(el);
        return;
    }
    int last = v.back();
    v.pop_back();
    fn(v, el);
    v.push_back(last);
}

void sort_fn(vector<int>& v) {
    if (v.size() == 1) return;
    int el = v.back();
    v.pop_back();
    sort_fn(v);
    fn(v, el);
}

int main() {
    vector<int> v; int n;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort_fn(v);

    for (auto& el : v) {
        cout << el << " ";
    }

    return 0;
}