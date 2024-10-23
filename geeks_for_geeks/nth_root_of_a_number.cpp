#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool is_possible(long long int x, long long int mid) {
        return mid * mid <= x;
    }

public:
    int mySqrt(int x) {
        long long int ans = -1;
        long long int start = 0;
        long long int end = x;
        while (start <= end) {
            long long int mid = start + (end - start) / 2;

            if (is_possible(x, mid)) {
                ans = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return ans;
    }
};

int main() {


    return 0;
}