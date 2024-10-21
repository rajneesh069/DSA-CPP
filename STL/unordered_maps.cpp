#include <bits/stdc++.h>
using namespace std;
// all functions of ordered and unordered maps are same

int main() {
    unordered_map<int, string> m;
    // 1. inbuilt implementation -> uses hashing and hashtables
    // 2. time complexity -> O(1) is average.
    // 3. valid keys datatype -> complex datatype can't be keys
    // unordered_map<pair<int, int>, string> m1; -> can't compile
    // because hash functions of these things aren't internally defined
    m[1] = "abc";
    m[3] = "bce";
    cout << m.size() << endl; //gives the size of the map
    //Example: given Q queries and N strings, print the frequency of the strings given in each query.
    unordered_map<string, int> m1;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        m1[s]++;  // accessing and insertion is O(1)
    }
    int Q;
    cin >> Q;
    while (Q--) { //total time complexity for this loop is q*(length of string)
        string s;
        cin >> s;
        cout << m1[s] << endl; // accessing and insertion is O(1)
    }

    // multimaps : O(logN) time complexity for everything
    multimap<string, int> mm;

   // Insert elements
    mm.insert({ "Alice", 90 });
    mm.insert({ "Bob", 85 });
    mm.insert({ "Alice", 95 });

    // Accessing elements
    auto range = mm.equal_range("Alice");
    for (auto it = range.first; it != range.second; ++it) {
        cout << it->first << ": " << it->second << endl;
    }
    return 0;
}