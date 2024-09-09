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

    int start = 0, end = -1, c = -1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (v[mid] == target) {
            c = mid;
            break;
        } else if (v[mid] < target) {
            start = mid - 1;
        } else {
            c = mid;
            end = mid - 1;
        }
    }

    cout << c << " " << (c == -1 ? -1 : v[c]);

    return 0;
}