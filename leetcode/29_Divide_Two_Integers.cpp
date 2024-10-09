#include <bits/stdc++.h>
using namespace std;

int divide(int dividend, int divisor) {
    bool is_negative = (dividend < 0) ^ (divisor < 0);

    if (divisor == -1) {
        if (dividend == INT_MIN) return INT_MAX;
        return -dividend;
    }
    if (dividend == 0)
        return 0;
    if (dividend == divisor)
        return 1;
    if (divisor == 1)
        return dividend;

    long long q = 0;
    long long d1 = abs(divisor);  // divisor
    long long d2 = abs(dividend); // dividend

    // what we need to find is d2/d1

    while (d2 >= d1) {
        long long temp = d1, multiple = 1;
        while (d2 >= (temp << 1)) {
            temp <<= 1;
            multiple <<= 1;
        }
        d2 -= temp;
        q += multiple;
    }

    if (is_negative) {
        q = -q;
    }

    if (q > INT_MAX) {
        return INT_MAX;
    }

    if (q < (INT_MIN)) {
        return INT_MIN;
    }

    return q;
}

int main() {
    int dividend, divisor;
    cin >> dividend >> divisor;
    cout << divide(dividend, divisor);

    return 0;
}