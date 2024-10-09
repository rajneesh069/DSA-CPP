#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n); // works best on sorted data structures

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    int* ptr = lower_bound(a, a + n, 26); // finds the pointer/iterator of that value or the value just greater than that
    if (ptr == (a + n)) {
        cout << "Not Found" << endl;

    }
    else {
        cout << (*ptr) << endl;
    }

    int* ptr_restricted = lower_bound(a + 1, a + n, 5); // range can be restrictive too
    if (ptr_restricted == (a + n)) {
        cout << "Not Found";
    }
    else {
        cout << (*ptr_restricted) << endl;
    }
    int* ptr_upper_bound = upper_bound(a, a + n, 5);
    if (ptr_upper_bound != a + n) cout << *ptr_upper_bound << endl;

    return 0;
}