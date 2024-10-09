#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> prime_factors;
    // 1. O(N) approach
    /* for (int i = 2; i <= n; i++) {
        while (n % i == 0) {
            prime_factors.push_back(i);
            n /= i;
        }
    } */

   // 2. O(sqrt(N)) approach
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            prime_factors.push_back(i);
            n /= i;
        }
    }

    if (n > 1) { // the last prime number which would be left will be caught by this
        prime_factors.push_back(n);
    }

    for (int prime : prime_factors) {
        cout << prime << " ";
    }

    return 0;
}