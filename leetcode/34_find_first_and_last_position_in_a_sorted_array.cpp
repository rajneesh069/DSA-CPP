#include <bits/stdc++.h>
using namespace std;

// to get the last position break the loop with start=mid+1
// to get the first position break the loop with end = mid-1

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> v(2, -1);
    int n = nums.size();
    int start = 0, end = n - 1;
    int ans = -1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (nums[mid] == target) {
            ans = mid;
            start = mid + 1;
        } else if (nums[mid] > target) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    v[1] = ans;
    start = 0;
    end = n - 1;
    ans = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (nums[mid] == target) {
            ans = mid;
            end = mid - 1;
        } else if (nums[mid] < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    v[0] = ans;
    return v;
}

int main() {


    return 0;
}