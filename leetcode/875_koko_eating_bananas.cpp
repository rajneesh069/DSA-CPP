#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool is_possible(vector<int>& piles, int h, int mid) {
        int n = piles.size();
        for (int i = 0; i < n; i++) {
            if (mid >= piles[i]) {
                h--;
            } else {
                if (piles[i] % mid == 0) {
                    h -= piles[i] / mid;
                } else {
                    h -= (piles[i] / mid) + 1;
                }
            }
        }

        return h >= 0;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int end = *max_element(piles.begin(), piles.end());
        int ans = -1;
        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (is_possible(piles, h, mid)) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return ans;
    }
};

int main() {


    return 0;
}