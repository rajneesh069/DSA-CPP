#include <bits/stdc++.h>
using namespace std;

int countSetBits(int n) {
    int count = 0;
    for (int i = 0; (1 << i) <= n; ++i) {
        int bitMask = (1 << (i + 1)); // Size of full cycles
        int completeCycles = n / bitMask; // Number of complete cycles
        int remaining = n % bitMask; // Remaining numbers after full cycles

        count += completeCycles * (bitMask / 2) + max(0, remaining - (bitMask / 2) + 1);
    }
    return count;
}

int main() {

    int n;
    cin >> n;
    cout << countSetBits(n);
    return 0;
}