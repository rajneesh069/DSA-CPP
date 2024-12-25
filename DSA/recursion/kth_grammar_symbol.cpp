#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int fn(int n, int k) {
        if (n == 1 && k == 1) return 0;

        int mid = pow(2, n - 2);
        if (k <= mid) {
            return fn(n - 1, k);
        } else {
            return !fn(n - 1, k - mid);
        }
    }
public:
    int kthGrammar(int n, int k) {
        return fn(n, k);
    }
};

int main() {


    return 0;
}