#include <bits/stdc++.h>
using namespace std;

// iterators short forms and range based loops

int main() {
     // 'auto' keyword -> it assumes/finds the data type of the variable automatically.
    auto a = 1.0; // 'a' is assumed to be float now.
    // in case of iterators it is particularly more useful because we don't have to write
    // the whole syntax of iterators.

    vector<int> v = { 2,3,6,7 };
    // conditional loop
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";

    }
    cout << endl;

    // vector<int> ::iterator it;
    // for (it = v.begin(); it < v.end(); it++) {
    //     cout << *(it) << " ";
    // }
    // cout << endl;
    // we can use auto here, instead of defining the iterator directly 'auto' can be used in the for loop
    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *(it) << " ";
    }
    cout << endl;

    //range based loops directly iterate over elements and could be used on all containers
    for (auto el : v) { // right now, 'el' is the copy of values in 'v'
        el++; //-> this line will have no effect on the elements of 'v'
    }
    for (auto& el : v) {
        el++; // this will actually change the values of 'v' as it is a reference variable
    }
    for (auto el : v) {
        cout << el << " ";
    }
    cout << endl;

    vector<pair<int, int>> v_p = { {1,2}, {2,3},{3,4} };
    for (auto& value : v_p) {
        cout << value.first << " " << value.second << endl;
    }



    return 0;
}