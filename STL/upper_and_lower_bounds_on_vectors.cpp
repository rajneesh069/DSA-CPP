#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int>a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    auto it = lower_bound(a.begin(), a.end(), 26); // finds the pointer/iterator of that value or the value just greater than that
    if (it == (a.end())) {
        cout << "Not Found" << endl;

    }
    else {
        cout << (*it) << endl;
    }

    auto it_restricted = lower_bound(a.begin(), a.end(), 5); // range can be restrictive too
    if (it_restricted == (a.end())) {
        cout << "Not Found";
    }
    else {
        cout << (*it_restricted) << endl;
    }
    auto it_upper_bound = upper_bound(a.begin(), a.end(), 5); // always returns the iterator to the next greater element
    if (it_upper_bound != a.end()) cout << *it_upper_bound << endl;
    return 0;
}