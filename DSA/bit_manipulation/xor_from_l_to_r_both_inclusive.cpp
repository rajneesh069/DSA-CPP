#include <bits/stdc++.h>
using namespace std;

int xorUpto(int a) { // xor from 0 to a(both inclusive)
    switch (a % 4) {
    case 0: return a;
    case 1: return 1;
    case 2: return a + 1;
    case 3: return 0;
    }
    return 0;
}

int xor_from_l_to_r(int l, int r) { // both inclusive
    return xorUpto(l - 1) ^ xorUpto(r);
}


int main() {
    int l, r;
    cin >> l >> r;
    cout << xor_from_l_to_r(l, r);
    return 0;
}