#include <bits/stdc++.h>
using namespace std;
/*
    1. maps : stores key-value pairs
    2. normal maps : sorted order -> implemented using Red Black Trees
    3. unordered maps : unsorted
    4. iterator+1 cannot be done, as there's no continguous memory allocation
    5. maps(normal/ordered ones obviously) contain unique keys only, if we re-assign a value to the key
    of a map it will change the value of that key then.
*/

int main() {
    map<int, string> m;
    m[1] = "abc"; // 1 is the key and "abc" is its value
    m[5] = "cdc"; // insertion and accessing takes O(logN) because of sorting
    m[3] = "acd";
    m[6]; // even this takes O(logN), and default value is empty string for string type values,
    // and for 'int' and 'float' its 0.
    cout << m.size()<<endl; //gives the size of the map
    map <int, string> ::iterator it; // iterator for map, inside its a pair.
    for (it = m.begin(); it != m.end(); it++) {
        // 'it < map.end()' doesn't make sense as there's no continuous memory location
        cout << it->first << " " << it->second << endl;
        // or cout << (*it).first << " " << (*it).second << endl;
    }

    // using auto keyword
    for (auto& el : m) {
        cout << el.first << " " << el.second << endl;
    }

    // these loops take N(logN) time complexity, as accessing take logN time and there's a loop which runs N times.

    auto iter = m.find(3); // O(logN) time complexity.
    if (iter == m.end()) {
        cout << "No Value";
    }
    else {
        cout << iter->first << " " << iter->second << endl;
    }
    // returns m.end() if the value is not found.
    m.erase(3); // takes key as well as iterator's value as well, O(logN)
    auto iter1 = m.find(4);
    if (iter1 != m.end()) {
        m.erase(iter1);
    }
    m.clear(); // clears the whole map


    map<string, string> m1;
    // insertion time complexity depends on the keys as well.
    // so this time lexicographical comparison will happen and it will become s.size() * O(logN);
    m1["abcd"] = "abc";
    return 0;
}