#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        multiset<long long> m;
        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;
            m.insert(x);
        }
        long long sum = 0;
        for (int i = 0; i < k; i++) {
            auto it = --m.end();
            sum += *it;
            m.erase(it);
            m.insert((*it) / 2);
        }
        cout << sum << endl;
        m.clear();
    }

    return 0;
}