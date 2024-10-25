#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool is_possible(vector<int>& v, int days, int mid) {
        long long int n = v.size();
        long long int temp = mid;
        for (int i = 0; i < n; i++) {
            if (temp < v[i]) {
                days -= 1;
                temp = mid;
                if (days <= 0 || temp < v[i]) return false;
            }
            temp -= v[i];
        }
        days--;
        return days >= 0;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        long long int start = *max_element(weights.begin(), weights.end());
        long long int end = accumulate(weights.begin(), weights.end(), 0);
        long long int ans = -1;

        while (start <= end) {
            long long int mid = start + (end - start) / 2;

            if (is_possible(weights, days, mid)) {
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