#include <bits/stdc++.h>
using namespace std;

int m = (1e9 + 7);

class Solution {
private:
    int power(long long int a, long long b) {
        if (a == 1) return 1; // agar base hi 1 hai toh execute hi mat karo aage

        if (b == 0) {
            return 1; // kisi ki power zero toh 1    
        }

        int temp = power(a, b / 2) % m;
        if (b % 2 == 0) {
            return (1LL * temp * temp) % m;
        }

        return (1LL * a * temp * temp) % m;
    }
public:
    int countGoodNumbers(long long n) {
        long long int even = ceil(n / 2.0);
        long long int odd = n / 2;
        return ((1LL * power(5, even)) % m * (1LL * power(4, odd)) % m) % m;
    }
};

int main() {


    return 0;
}