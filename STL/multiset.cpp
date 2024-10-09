#include <bits/stdc++.h>
using namespace std;
int main() {
    multiset<string> s;
    s.insert("abc"); // O(logN)
    s.insert("bcd");
    s.insert("abc");
    s.insert("abc");
    s.insert("zsdf");
    cout << s.size() << endl; //gives size of the multiset
    auto it = s.find("abc"); // O(logN), returns the iterator of the first instance it finds, else it returns 's.end()'
    if (it != s.end()) s.erase(it); // deletes just the first instance of "abc",
    // which is being pointed by the iterator.
    s.erase("abc"); // deletes all instances of abc from the set.
    return 0;

}