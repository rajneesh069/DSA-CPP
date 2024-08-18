#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ct = 0;   // count of divisors
    int sum = 0;  // sum of divisors
    /* 1. naive approach : O(N) method
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) cout << i << endl;
    }
    */

    // 2. O(sqrt(n)) method
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            cout << i << " " << n / i << "\n";
            ct++;
            sum += i;
            if (n / i != i) {
                ct++;
                sum += n / i;
            }
        }
    }
    cout << "ct: " << ct << ", sum: " << sum << "\n";

    
    return 0;
}