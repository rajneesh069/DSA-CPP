#include <bits/stdc++.h>
using namespace std;

void printVec(vector<int>& v) {  // passed by reference because otherwise it will pass a copy
    // and that takes O(N) time complexity
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}


int main() {
    vector<int> v(10, -1); // size = 10, all values = -1
    vector<int> v1 = v; // makes a copy of v into v1, takes O(N) time complexity
    vector<int>& v2 = v; // makes a reference variable of v
    printVec(v); //print the vector
    
    pair<int, int> p;
    // p = make_pair(2, 3);
    p = { 2,3 }; // another way to initialize pair, more handy
    int a = p.first; // gives the first value
    int b = p.second; // gives the second value

    // suppose we needed relation between elements of two arrays
    int arr[3] = { 1,2,3 };
    int brr[3] = { 4,5,6 };
    pair<int, int> p1[3];
    p1[0] = { arr[0],brr[0] };
    p1[1] = { arr[1],brr[1] };
    p1[2] = { arr[2],brr[2] };

    swap(p1[0], p1[2]); // can swap easily obviously.

    for (int i = 0; i < 3; i++) {
        cout << p1[i].first << " " << p1[i].second << endl;
    }

    return 0;
}