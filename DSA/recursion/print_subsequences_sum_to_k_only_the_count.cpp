#include <bits/stdc++.h>
using namespace std;

int print_subsequences_sum_to_k_only_the_count( int arr[], int n, int i, int sum) {
    if (i >= n) {
        if (sum == 2) {
            return 1;
        }
        else {
            return 0;
        }
    }

    // take
    sum += arr[i];
    int left = print_subsequences_sum_to_k_only_the_count( arr, n, i + 1, sum);
    sum -= arr[i];

    // not take
    int right = print_subsequences_sum_to_k_only_the_count( arr, n, i + 1, sum);

    return left + right;
}

int main() {
    int n = 3;
    int arr[n] = { 1,2,1 };
    int ans = print_subsequences_sum_to_k_only_the_count(arr, n, 0, 0);
    cout << ans;
    return 0;
}