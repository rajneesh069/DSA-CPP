#include <bits/stdc++.h>
using namespace std;

//comparator function for bubble sort
// bool should_i_swap(pair<int, int>a, pair<int, int> b) {
//     if (a.first != b.first) {
//         if (a.first > b.first) return true;
//     }
//     else {
//         if (a.second < b.second) return true;
//     }
//     return false;
// }

//comparator function for inbuilt sort function
// bool should_i_swap(pair<int, int>a, pair<int, int> b) {
//     if (a.first != b.first) {
//         if (a.first > b.first) return false;
//     }
//     else {
//         if (a.second < b.second) return false;
//     }
//     return true;
// }

// comparator function for introsort but in a simpler way
// return whatever you want the comparator function to do!
bool should_i_swap(pair<int, int>a, pair<int, int> b) {
    if (a.first != b.first) {
        return a.first < b.first;
    }
    return a.second > b.second;
}


int main() {
    int n;
    cin >> n;
    vector<pair<int, int>>a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    // Bubble sort in O(n^2)
    // for (int i = 0; i < n; i++) {
    //     for (int j = i + 1; j < n; j++) {
    //         if (should_i_swap(a[i], a[j])) swap(a[i], a[j]);
    //     }
    // }

    sort(a.begin(), a.end(), should_i_swap); // return whatever you want the 
    // comparator function to do

    for (int i = 0; i < n; i++) {
        cout << a[i].first << " " << a[i].second << endl;
    }
    cout << endl;


    return 0;
}