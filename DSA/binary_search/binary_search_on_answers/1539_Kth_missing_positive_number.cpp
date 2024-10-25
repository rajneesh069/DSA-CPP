#include <bits/stdc++.h>
using namespace std;

class Solution {

public:
    int findKthPositive(vector<int>& v, int k) {
        int left = 0, right = v.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int missing = v[mid] - (mid + 1);

            if (missing < k) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return left + k;
    }
};

int main() {


    return 0;
}