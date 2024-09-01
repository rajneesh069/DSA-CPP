#include <bits/stdc++.h>
using namespace std;

bool uniqueOccurrences(vector<int>& v) {
    unordered_map<int, int> f;
    for (auto& it : v) {
        f[it]++;
    }
    unordered_set<int>o;
    for (auto& el : f) {
        if (!o.insert(el.second).second) {
            return false;
        }
    }
    return true;
}

int main() {


    return 0;
}