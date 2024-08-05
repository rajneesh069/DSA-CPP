#include <bits/stdc++.h>
using namespace std;

void reverse(int arr[], int n, int i = 0)
{
    if (i >= n / 2) {
        return;
    }
    int temp = arr[i];
    arr[i] = arr[n - i - 1];
    arr[n - i - 1] = temp;
    reverse(arr, n, i + 1);
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    reverse(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " " << endl;

    }

    return 0;
}