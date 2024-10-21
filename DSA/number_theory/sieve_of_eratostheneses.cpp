// pre-compute all the numbers
#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 10;
vector<bool> isPrime(N, 1);

int main() {
    isPrime[0] = isPrime[1] = false;
    // sieve algorithm -> precompute all the primes in the given range
    // O(NloglogN) -> time complexity, smaller than O(NlogN)
    for (int i = 2; i < N; i++) {
        if (isPrime[i] == true) {
            for (int j = 2 * i; j < N; j += i) {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 1; i < 100; i++) {
        cout << i << ": " << (isPrime[i] == true ? "true" : "false") << "\n";
    }

    return 0;
}