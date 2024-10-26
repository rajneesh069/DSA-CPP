#include <bits/stdc++.h>
using namespace std;

// Unoptimal approach 
//Time Complexity: O(N + max_el*(logN))
//Space Complexity : O(1)
class Solution {

public:
    int findKthPositive(vector<int>& v, int k) {
        int n = v.size(), max_el = v[n - 1];

        int ct = 0;
        for (int i = 1; i <= max_el; i++) {
            bool is_found = false;
            int start = 0, end = n - 1;

            while (start <= end) {
                int mid = start + (end - start) / 2;
                if (v[mid] == i) {
                    is_found = true;
                    break;
                } else if (v[mid] < i) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }

            if (!is_found) {
                ct++;
            }

            if (ct == k) {
                return i;
            }
        }

        return max_el + (k - ct);
    }
};

class Solution2 {
public:
    int findKthPositive(vector<int>& v, int k) {
        int start = 0, end = v.size() - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            int missing = v[mid] - (mid + 1);

            if (missing < k) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return start + k;
    }

};

int main() {


    return 0;
}