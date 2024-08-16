#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    // all of these internal algorithms take up a range to operate in on a data structure.

    int min = *min_element(v.begin(), v.end());
    cout << min << endl;

    int max = *max_element(v.begin(), v.end());
    cout << max << endl;

    int count_of_an_element = count(v.begin(), v.end(), 2);
    cout << count_of_an_element << endl;

    int sum = accumulate(v.begin(), v.end(), 0); // initial sum taken to be 0, if it is taken something else, it would be added to the final sum
    cout << sum << endl;

    auto it = find(v.begin(), v.end(), 6); //returns the iterator/pointer of that element, if not found then of the next to last element
    if (it != v.end()) cout << *it << endl;
    else cout << "Element Not Found" << endl;

    // reverses the original data structure
    reverse(v.begin(), v.end());
    // comes in handy in case of arrays, vectors and strings especially
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    string s = "dfbhfew";
    reverse(s.begin() + 2, s.end()); // reverses from 2nd index to the last
    cout << s << endl;

    return 0;
}