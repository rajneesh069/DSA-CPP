#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool is_possible(int arr[], int mid, int k, int n) {
        int p = 1, t = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] > mid) return false;

            if ((arr[i] + t) <= mid) {
                t += arr[i];
            } else {
                p++;
                t = 0;
                t += arr[i];
            }

            if (p > k) {
                return false;
            }
        }

        return true;
    }

public:
    long long minTime(int arr[], int n, int k) {
        int start = 0, end = 1e9, ans = -1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (is_possible(arr, mid, k, n)) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return ans;
    }
};


// optimized code

class OptimizedSolution {
private:
    bool is_possible(int arr[], long long int mid, int k, int n) {
        int p = 1, t = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] > mid) return false;

            if ((arr[i] + t) <= mid) {
                t += arr[i];
            } else {
                p++;
                t = 0;
                t += arr[i];
            }

            if (p > k) {
                return false;
            }
        }

        return true;
    }

public:
    long long minTime(int arr[], int n, int k) {
        long long int start = *max_element(arr, arr + n); // Minimum possible time is the max partition size
        long long int end = accumulate(arr, arr + n, 0LL); // Maximum possible time is sum of all partitions
        long long int ans = -1;

        while (start <= end) {
            long long int mid = start + (end - start) / 2;

            if (is_possible(arr, mid, k, n)) {
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