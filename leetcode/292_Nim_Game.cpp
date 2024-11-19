#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool fn(int n, int me) {
        if (n == 1 || n == 2 || n == 3)
            return me;
        if (me) {
            return fn(n - 1, !me) || fn(n - 2, !me) || fn(n - 3, !me);
        } else {
            return fn(n - 1, !me) && fn(n - 2, !me) && fn(n - 3, !me);
        }
    }
public:
    bool canWinNim(int n) {
        // bool me = true;
        // return fn(n, me);
        return n % 4 != 0;
    }
};


int main() {


    return 0;
}