#include <bits/stdc++.h>
using namespace std;

int setBit(int n) {
    if (n == 0) return 1;

    int rightmost_unset_bit = (~n) & (n + 1);
    return n | rightmost_unset_bit;
}

int main() {
    int n;
    cin >> n;
    cout << setBit(n);
    return 0;
}