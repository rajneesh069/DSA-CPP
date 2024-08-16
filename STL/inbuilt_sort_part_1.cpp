#include <bits/stdc++.h>
using namespace std;


int main() {
    //Introsort -> inbuilt sort algorithm = quick sort + heap sort + insertion sort
    int n;
    cin >> n;
    // int a[n];
    vector<int>a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // sort(a + 3, a + n); // takes starting address and (ending+1) address
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;


    return 0;
}