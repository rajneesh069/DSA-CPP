#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    bool is_prime = true;
    // 1. O(N) - naive approach
    /* for (int i = 2; i < n; i++) {
        if (n == 1) {
            is_prime = false;
            break;
        }
        if (n % i == 0) {
            is_prime = false;
            break;
        }
    } */

   //2. O(sqrt(N))
    for (int i = 2; i * i <= n; i++) {
        if (n == 1) {
            is_prime = false;
            break;
        }
        if (n % i == 0) {
            is_prime = false;
            break;
        }
    }

    cout << is_prime << "\n";


    return 0;
}