#include <bits/stdc++.h>
using namespace std;

void print_set(set<string>& s) {
    for (auto& el : s) {
        cout << el << " ";
    }
    cout << endl;
}

int main() {
    // ordered set: Everything is like map's time complexity, i.e., O(logN).
    // sets only contain unique elements
    set<string> s;
    s.insert("abc");
    s.insert("zsd");
    s.insert("bcd");
    // s["abc"] -> it doesn't exist, we use '.find()' method for this.
    auto it = s.find("abc"); // gives iterator if it exists or returns end iterator if it doesn't.
    s.erase("abc"); // it also takes iterators
    if (it != s.end()) s.erase(it);

    unordered_set<int> us;
    // Exactly like Unordered map, every function is same with ordered sets but it takes O(1) time complexity on an average.


    return 0;
}