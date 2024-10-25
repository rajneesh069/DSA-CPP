#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool is_possible(vector<int>& v, int threshold, int mid) {
        long long int n = v.size();
        long long int sum = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] % mid == 0) {
                sum += v[i] / mid;
            } else {
                sum += v[i] / mid + 1;
            }
        }
        if (sum <= threshold) return true;
        return false;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        long long int start = 1;
        long long int end = *max_element(nums.begin(), nums.end());
        long long int ans = -1;

        while (start <= end) {
            long long int mid = start + (end - start) / 2;

            if (is_possible(nums, threshold, mid)) {
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