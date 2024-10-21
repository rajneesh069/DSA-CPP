#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }
    // auto it = lower_bound(s.begin(), s.end(), 5); // this is NOT O(logN) but O(N)
    // for sets use set.lower_bound() function, as it uses tree implementation to traverse
    auto it_set = s.lower_bound(5);
    if (it_set != s.end()) cout << *it_set << endl;
    auto it_set_upper_bound = s.upper_bound(4);
    if (it_set_upper_bound != s.end()) cout << *it_set_upper_bound << endl;

    map<int, int>m;
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int x;
        int y;
        cin >> x >> y;
        m[x] = { y };
    }
    auto it_map = m.lower_bound(3); // works on keys only!
    if (it_map != m.end()) cout << (it_map)->first << " " << it_map->second << endl;
    auto it_map_upper_bound = m.upper_bound(4);
    if (it_map_upper_bound != m.end()) cout << it_map_upper_bound->first << " " << it_map_upper_bound->second << endl;

    return 0;
}