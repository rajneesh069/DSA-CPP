#include <bits/stdc++.h>
using namespace std;


int main() {
    // iterators point to the elements of a container.
    vector<int> v = { 2,3,6,7 };
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << "\n";
    vector<int> ::iterator it = v.begin(); // v.begin() points to v[0]
    cout << (*(it + 1)) << endl; // prints the value 3 from v.
    for (it = v.begin(); it != v.end(); ++it) { //v.end() points to the next position of the last element
        cout << *(it) << endl;
    }

    // in case of iterators there's a difference between 'it++' and 'it+1'
    /*
        For vectors it's the same because vector has contiguous memory allocation,
        but in case of maps and sets, the memory allocation couldn't be contiguous leading
        to wrong memory locations, in case of 'it+1', because it will take the iterator
        to the next memory location, whereas 'it++' or '++it' will take the iterator to the
        location of the next iterator, that's why we use 'it++' or '++it' instead of
        'it+1'.

     */

    vector<pair<int, int>> v_p = {
        {1,2}, {2,3}, {3,4},{4,5}
    };
    vector<pair<int, int>> ::iterator it1;
    // 'it1' is an iterator that will point to the pairs in the vector
    for (it1 = v_p.begin(); it1 != v_p.end(); it++) {
        cout << (it1)->first << " " << it1->second << endl;
    }
    for (it1 = v_p.begin(); it1 != v_p.end(); it++) {
        cout << (*it1).first << " " << (*it1).second << endl;
    }
    return 0;
}