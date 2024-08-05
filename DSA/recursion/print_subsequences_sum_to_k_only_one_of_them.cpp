#include <bits/stdc++.h>
using namespace std;

bool print_subsequences_sum_to_k_only_one_of_them(vector<int>& current, int arr[], int n, int i, int sum) {
    if (i >= n) {
        if (sum == 2) {
            for (auto elem : current) {
                cout << elem << " ";
            }
            cout << endl;
            return true;
        }
        else {
            return false;
        }
    }

    // take
    current.push_back(arr[i]);
    sum += arr[i];
    if (print_subsequences_sum_to_k_only_one_of_them(current, arr, n, i + 1, sum) == true) {
        return true;
    }
    current.pop_back();
    sum -= arr[i];

    // not take
    if (print_subsequences_sum_to_k_only_one_of_them(current, arr, n, i + 1, sum) == true) {
        return true;
    }

    return false;
}

int main() {
    int n = 3;
    int arr[n] = { 1,2,1 };
    vector<int> current;
    print_subsequences_sum_to_k_only_one_of_them(current, arr, n, 0, 0);
    return 0;
}