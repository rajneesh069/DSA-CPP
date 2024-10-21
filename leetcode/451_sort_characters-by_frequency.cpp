#include <bits/stdc++.h>
using namespace std;

string frequencySort(string s) {
    unordered_map<char, int> f;

    for (int i = 0; i < s.size(); i++) {
        if (f.find(s[i]) != f.end()) {
            f[s[i]]++;
            continue;
        }
        f[s[i]] = 1;
    }

    vector<pair<int, char>> v;
    for (auto& it : f) {
        v.push_back({ it.second, it.first });
    }

    sort(v.begin(), v.end(),
        [](auto a, auto b) { return a.first > b.first; });

    string ans = "";
    for (auto& it : v) {
        for (int i = 0; i < it.first; i++) {
            ans.push_back(it.second);
        }
    }
    return ans;
}


int main() {


    return 0;
}