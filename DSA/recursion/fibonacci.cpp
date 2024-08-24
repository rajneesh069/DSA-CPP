#include <bits/stdc++.h>
using namespace std;

int f(int n) {
    if (n <= 1) return n;
    // return f(n - 1) + f(n - 2); //-> either do this, or the following
    int last = f(n - 1);
    int second_last = f(n - 2);
    return last + second_last;
}

int main() {
    int n;
    cin >> n;
    cout << f(n);
    return 0;
}