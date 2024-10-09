#include <bits/stdc++.h>
using namespace std;


int main() {
    // works for sorted array ofc
    int n, target;
    cin >> n >> target;
    int v[n];
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int start = 0, end = n - 1, f = -1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (v[mid] == target) {
            f = mid;
            break;
        } else if (v[mid] > target) {
            end = mid - 1;
        } else {
            f = mid;
            start = mid + 1;
        }
    }
    cout << f << (f == -1 ? -1 : v[f]) << "\n";

    return 0;
}