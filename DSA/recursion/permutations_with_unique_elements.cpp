#include <bits/stdc++.h>
using namespace std;

void permutations(int j, vector<int>& v, vector<int>& ds, int f[]) {
    if (ds.size() == v.size()) {
        for (auto&& it : ds) {
            cout << it << " ";
        }
        cout << "\n";
    }

    for (int i = 0; i < v.size(); i++) {
        if (f[i] != 1) {
            f[i] = 1;
            ds.push_back(v[i]);
            permutations(i + 1, v, ds, f);
            ds.pop_back();
            f[i] = 0;
        }
    }

}


int main() {
    vector<int> v = { 1,2,2 };
    vector<int> ds;
    int f[v.size()] = { 0 };
    permutations(0, v, ds, f);
    return 0;
}