#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    int sumX = 0, sumY = 0, sumZ = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x; sumX += x;
        int y; cin >> y; sumY += y;
        int z; cin >> z; sumZ += z;
    }

    if (sumX == 0 && sumY == 0 && sumZ == 0) {
        cout << "YES" << "\n";
    }
    else {
        cout << "NO" << "\n";
    }

    return 0;
}