#include <bits/stdc++.h>
using namespace std;

vector<int> findPrimeFactors(int N) {
    int i = 2;
    vector<int> ans;
    while (i * i <= N) {
        if (N % i == 0) {
            while (N % i == 0) {
                ans.push_back(i);
                N /= i;
            }

        }
        i++;
    }
    if (N != 1) ans.push_back(N);
    return ans;
}


int main() {


    return 0;
}