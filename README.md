# C++ Standard Template Library(STL)

## Strings

- size(): returns size of the string
- getline(cin, str): takes the whole line as input
- To take very large data as input, use strings and then write proper algos to deal with them
- Try not to add characters to string directly, instead use push_back() function to append characters to the string

```cpp
#include <bits/stdc++.h>
using namespace std;


int main() {
    string s1 = "Hello";
    // string s2 = "World";
    string s2 = "Hello";
    cout << s1 + " " + s2 << endl;

    if (s1 == s2) {
        cout << "Equal" << endl;
    }
    else {
        cout << "Not equal" << endl;
    }
    // to access elements we can use it by using the index
    // each element is a character
    s1[0] = 'c';
    // we can re-assign individual characters of a string
    cout << s1.size() << endl;

    for (int i = 0; i < s1.size(); i++) {
        cout << s1[i] << " ";
    }
    cout << endl;
    // to take the whole line as input
    int t;
    cin >> t;
    cin.ignore(); // so that we can ignore extra space
    while (t--)
    {
        string str;
        getline(cin, str);
        cout << str << endl;
    }

    // reverse a string
    string ans;
    cin >> ans;
    for (int i = 0; i < ans.size(); i++) {
        ans.push_back(ans[i]); // don't add characters to string, not a good practice
    }

    return 0;
}
```

## Vectors and Pairs in STL

- Vectors are dynamic arrays with no fixed size.
- v[i] isn't accessible until there's something inside the vector.
- Pairs are containers used to store related data.
- When a pair is swapped the whole pair is swapped.

```cpp
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
```

## Nesting Vectors and Pairs

- Pairs can be nested in the vectors to form vector of pair, where each element is a pair instead of 'int' or 'char' or 'bool'.
- Vectors can be nested to form 2D dynamic arrays.
- Remember, that in case of nested vectors each `v[i]` represents a vector, so to access a 2D or 3D vector using `v[i]` there needs to be some vector(s) inside it.

```cpp
#include <bits/stdc++.h>
using namespace std;

void printVec(vector<pair<int, int>>& v) {
    cout << "size: " << v.size() << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i].first << " " << v[i].second << endl;
    }
}

void printVec(vector<int>& v) {
    cout << "size: " << v.size() << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}


int main() {
    // vector of pairs
    vector<pair<int, int>> v = {
     {1,2}, {2,3}, {3,4}
    };
    printVec(v);

    // array of vectors
    int N; // number of vectors inside the array
    cin >> N;
    vector<int> v1[N];
    for (int i = 0; i < N; i++) {
        int n; // size of each vector
        cin >> n;
        for (int j = 0; j < n; j++) {
            int x; // value inside each vector
            cin >> x;
            v1[i].push_back(x); // pushing x in the ith vector
        }
    }
    for (int i = 0; i < N; i++) {
        printVec(v1[i]);
    }

    vector<vector<int>> v2; // Vector of vectors : v2[i] -> vector
    int K;
    cin >> K;
    // now v2[i] cannot be accessed until there's something inside it.
    // so either create a temp vector and push everything in it and then
    // push it in the v2 vector or v2.push_back(vector<int> ());
    // Both will work
    for (int i = 0; i < K; i++) {
        int n;
        cin >> n;
        vector<int> temp;
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            temp.push_back(x);
        }
        v2.push_back(temp);
    }

    // print v2
    cout << "v2: " << endl;
    for (int i = 0; i < v2.size(); i++) {
        printVec(v2[i]);
    }
    return 0;
}
```

## Iterators in STL

- Iterators point to the elements of a container.
- Syntax : `container_type :: iterator it`, 'it' is the name of iterator, it could be named anything obviously.
- `begin()` points to the start position while `end()` points next to the last element of the container, NOT the last element but next to the last.
- In case of iterators there's a difference between `it++` and `it+1`
  - For vectors it's the same because vector has contiguous memory allocation,
    but in case of maps and sets, the memory allocation couldn't be contiguous leading
    to wrong memory locations, in case of 'it+1', because it will take the iterator
    to the next memory location, whereas 'it++' or '++it' will take the iterator to the
    location of the next iterator, that's why we use 'it++' or '++it' instead of
    'it+1'.

```cpp
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
```

## Concise Way of writing iterators using `auto` keyword and range based loops

- 'auto' keyword assumes the data type of a variable automatically.
- `Range based loops can iterate over the elements directly. It eliminates the need to dereference an iterator to get the value.`
- Both of them could be used together in case of containers to make the code concise and neat.

```cpp
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
```

## Maps

1. Maps : stores key-value pairs
2. Normal maps(ordered maps) : sorted order -> implemented using Red Black Trees
3. Unordered maps : unsorted order.
4. `*(iterator+1) cannot be done`, as there's no continguous memory allocation
5. Maps(unordered/ordered) contain unique keys only, if we re-assign a value to the key of a map, it will change the value of that key then.

### Ordered Maps: Insertion, Deletion and Accessing time complexity is O(logN)

- Worst case, Best Case and Average Case all have O(logN), however it may worsen in case of strings of long length as they need to lexicographically put in the map, then it will depend on string length too

```cpp
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
    m.erase(3); // takes key as well as iterator's value as well
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
```

#### Example

Given N strings, print unique strings in lexicographical order with their frequency.

- Constraints:
  - N <= 10<sup>5</sup>
  - s.length <= 100

```cpp
#include <bits/stdc++.h>
using namespace std;


int main() {
    int N;
    cin >> N;
    map<string, int> m; // map of strings and its frequency
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        if (!s.empty()) m[s]++;
    }
    for (auto& el : m) {
        cout << el.first << " " << el.second << endl;
    }

    return 0;
}
```

- Input

  8

  abc

  def

  abc

  ghj

  jkl

  ghj

  ghj

  abc

- Output

  abc 3

  def 1

  ghj 3

  jkl 1

### Unordered Maps : Average Insertion, Deletion and Accessing time complexity is O(1)

- Worst case : O(n)
- `Use unordered maps wherever possible to reduce time complexity.`
- Can't use complex data types like pairs as keys because the hash functions aren't defined internally.
- Basic data types are `int`, `float`, `string` etc. can be used.

```cpp
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

    // multimaps
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
```

- Multimaps could be used to store multiple values with a single key. Not frequently used atleast in CP and we can use ordered maps with vector<int/string> as the value to store multiple instances.

## Ordered, Unordered and Multi Sets

- size: to get the size of sets and maps(ordered, unordered and multi)

### Ordered Sets : Accessing, Deletion and Insertion Time Complexity is O(logN)

```cpp
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
    s.clear(); // clears the whole set
    return 0;
}
```

- Example
  - Given N strings, print unique strings in lexicographical order.
  - Constraints:
    N <= 10<sup>5</sup>, string.length=100000

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    set<string> s;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        s.insert(str);
    }
    for (auto& el : s) {
        cout << el << endl;
    }

    return 0;
}
```

- Example : [Sets-STL](https://www.hackerrank.com/challenges/cpp-sets/problem?fbclid=IwAR1Z1fv5RnGAqByvADCRUv4pYQAAmQ_zV5rgVVCagY-DneWu6TSWENdncsY)

```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    int q;
    cin >> q;
    set<int> s;
    while (q--)
    {
        int y, x;
        cin >> y >> x;
        if (y == 1) {
            s.insert(x);
        }
        else if (y == 2)
        {
            auto it = s.find(x);
            if (it != s.end()) s.erase(it);
        }
        else if (y == 3)
        {
            auto it = s.find(x);
            if (it != s.end()) {
                cout << "Yes" << endl;
            }
            else {
                cout << "No" << endl;
            }
        }
    }
    s.clear();
    return 0;

}
```

### Unordered Sets : Average Accessing, Deletion and Insertion Time Complexity is O(1)

- Functions are same like ordered set, just the time complexity is different.
- Similar to unordered maps, complex data types like pairs/sets/vectors can't be keys.
- Following is the example and code for unordered set:

```cpp
#include <bits/stdc++.h>
using namespace std;
// Given N strings and Q queries, print yes if the string is present in the query. N <= 10^5, string.length=100000

int main() {
    unordered_set<string> us;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        us.insert(s);
    }
    int Q;
    cin >> Q;
    while (Q--)
    {
        string s;
        cin >> s;
        auto it = us.find(s);
        if (it != us.end()) {
            cout << "yes" << endl;
            continue;
        }
        cout << "no" << endl;

    }

    return 0;
}
```

- (Unique Number of Occurences)[https://leetcode.com/problems/unique-number-of-occurrences/description/]

  - unordered_set<int>s; s.insert(2) returns a pair, in which first value is the iterator to that element in set and second is true/false depending on if the element was inserted.

```cpp
#include <bits/stdc++.h>
using namespace std;

bool uniqueOccurrences(vector<int>& v) {
    unordered_map<int, int> f;
    for (auto& it : v) {
        f[it]++;
    }
    unordered_set<int>o;
    for (auto& el : f) {
        if (!o.insert(el.second).second) {
            return false;
        }
    }
    return true;
}

int main() {


    return 0;
}
```

### Multisets : Allows multiple same values, O(logN) time complexity for everything generally.

- Allows multiple keys in the set in sorted manner.

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
    multiset<string> s;
    s.insert("abc"); // O(logN)
    s.insert("bcd");
    s.insert("abc");
    s.insert("abc");
    s.insert("zsdf");
    auto it = s.find("abc"); // O(logN), returns the iterator of the first instance it finds, else it returns 's.end()'
    if(it!=s.end()) s.erase(it); // deletes just the first instance of "abc",
    // which is being pointed by the iterator.
    s.erase("abc"); // deletes all instances of abc from the set.
    return 0;

}
```

Example : [The Monk and Class Marks](https://www.hackerearth.com/problem/algorithm/the-monk-and-class-marks/?fbclid=IwAR09BMLG-1NhqDlVQq0KIzSr8ZTgqrbJmdfnsXc7KnDiphgX5UmbFLoEYjE)

```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    multiset<pair<int, string>, function<bool(pair<int, string>, pair<int, string>)>> m(
        [](const pair<int, string>& a, const pair<int, string>& b) {
            if (a.first != b.first) {
                return a.first > b.first;
            }
            else {
                return a.second < b.second;
            }
        }
    );
    for (int i = 0; i < n; i++) {
        string name;
        int marks;
        cin >> name >> marks;
        m.insert({ marks, name });
    }

    for (auto& p : m) {
        cout << p.second << " " << p.first << endl;
    }

    m.clear();


    return 0;

}
```

- Example: [Monk and the Magical Candies](https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/monk-and-the-magical-candy-bags/?fbclid=IwAR2kDiVkEaxu9dkCTCUhzXLuIccNn0Gz3dSfkaSUjlDE6Nb9UHMzt8HNDo4)

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        multiset<long long> m;
        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;
            m.insert(x);
        }
        long long sum = 0;
        for (int i = 0; i < k; i++) {
            auto it = --m.end();
            sum += *it;
            m.erase(it);
            m.insert((*it) / 2);
        }
        cout << sum << endl;
        m.clear();
    }

    return 0;
}
```

### Nesting in Sets and Maps

- Only ordered sets and maps can be nested with complex data structures which could be compared somehow.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    map<pair<string, string>, vector<int>> m;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string fn, ln;
        int ct;
        cin >> fn >> ln >> ct;
        for (int j = 0; j < ct; j++) {
            int x;
            cin >> x;
            m[{fn, ln}].push_back(x);
        }
    }
    for (auto& pr : m) {
        auto& full_name = pr.first;
        auto& list = pr.second;
        cout << full_name.first << " " << full_name.second << endl;
        cout << list.size() << endl;
        for (auto& el : list)
        {
            cout << el << " ";
        }
        cout << endl;

    }

    return 0;
}
```

## Stack and Queue in STL

- Stack works on LIFO principle and the most handy functions it provides are as follows:

  - top: to retreive(not remove) the topmost element
  - push: to push elements onto the stack
  - pop: to pop the elements off the stack
  - size: to check the size of the stack

- Queue works on FIFO principle and the most common functions are:
  - front : to retrieve(not remove) the first element in the queue
  - push: to push elements in the back of the queue
  - pop: to pop elements from the front of the queue
  - size: to check the size of the queue

```cpp
#include <bits/stdc++.h>
using namespace std;


int main() {
    // Stack works on LIFO principle
    stack<int> s; // could be any data structure ofc
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout<<s.size()<<endl; //gives the size of the stack
    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }

    // Queue works on FIFO principle
    queue<string> q; // could be any data structure ofc
    q.push("abc");
    q.push("def");
    q.push("ghi");
    q.push("jkl");
    cout<<q.size()<<endl; //gives the size of the queue
    while (!q.empty())
    {
        cout << q.front() << endl;
        q.pop();
    }


    return 0;
}
```

### Examples for Stack and Queue along with concepts that will come in handy later

1. [Balanced Brackets](https://leetcode.com/problems/valid-parentheses/description/)

```cpp
    #include <bits/stdc++.h>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    unordered_map<char, int> symbols = { {'[', -1}, {'(',-2}, {'{', -3}, {']', 1}, {')',2}, {'}', 3} };
    for (char bracket : s)
    {
        if (symbols[bracket] < 0) {
            st.push(bracket);
        }
        else {
            if (st.empty()) return false;
            char top = st.top();
            st.pop();
            if (symbols[top] + symbols[bracket] != 0) return false;
        }
    }
    return st.empty();
}

// balanced brackets
int main() {

    cout << isValid("()");
    return 0;
}
```

2. [Next Greater Element](https://www.hackerrank.com/contests/second/challenges/next-greater-element/problem)

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> NGE(vector<int>& v) {
    stack<int> st;
    vector<int> nge(v.size());
    for (int i = 0; i < v.size(); i++) {
        while (!st.empty() && v[i] > v[st.top()]) {
            nge[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty())
    {
        nge[st.top()] = -1;
        st.pop();
    }
    return nge;
}


int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<int> nge = NGE(v);
    for (int i = 0; i < nge.size(); i++) {
        cout << v[i] << " " << (nge[i] == -1 ? -1 : v[nge[i]]) << endl;
    }
    return 0;
}
```

## Sorting(Introsort) in STL : O(NlogN) &rarr; Time Complexity

- `sort()` function takes the starting `address` and the `(ending+1) address` and can take a comparator function as well.

1. Sorting on vectors and arrays

```cpp
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
```

2. Sorting with comparator functions

```cpp
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
```

## Upper and Lower Bounds using STL : Works in O(logN) on sorted Data Structures and in O(N) on unsorted ones

### Lower Bound

- Returns the iterator to the first element in the range that is not less than (i.e., greater than or equal to) the specified value.
- Takes the range of addresses (start: inclusive, end: exclusive) on which the operation needs to be performed, and the value of which the lower bound needs to be found.
- If no element is greater than or equal to the specified value, it returns the end iterator of the range.

- Lower Bound on Arrays:

```cpp
#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n); // works best on sorted data structures

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    int* ptr = lower_bound(a, a + n, 26); // finds the pointer/iterator of that value or the value just greater than that
    if (ptr == (a + n)) {
        cout << "Not Found" << endl;

    }
    else {
        cout << (*ptr) << endl;
    }

    int* ptr_restricted = lower_bound(a + 1, a + n, 5); // range can be restrictive too
    if (ptr_restricted == (a + n)) {
        cout << "Not Found";
    }
    else {
        cout << (*ptr_restricted) << endl;
    }
    return 0;
}
```

- Lower bound on vectors

```cpp
#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int>a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    auto it = lower_bound(a.begin(), a.end(), 26); // finds the pointer/iterator of that value or the value just greater than that
    if (it == (a.end())) {
        cout << "Not Found" << endl;

    }
    else {
        cout << (*it) << endl;
    }

    auto it_restricted = lower_bound(a.begin(), a.end(), 5); // range can be restrictive too
    if (it_restricted == (a.end())) {
        cout << "Not Found";
    }
    else {
        cout << (*it_restricted) << endl;
    }
    return 0;
}
```

- Lower bound on sets and maps
  1. Use set.lower_bound() function instead of regular lower_bound() function, same for maps as well.
  2. Regular lower_bound() works as O(N) in case of sets and maps but map.lower_bound() function works in O(logN) as it uses trees internally to traverse through the map.
  3. set.lower_bound() or map.lower_bound() just takes the value as input, and returns the iterator of either that value if its present in the set/map or of the first just greater element in it.
  4. map.lower_bound() works just on the keys of the map and returns the iterator of the value in the map.

```cpp
#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }
    // auto it = lower_bound(s.begin(), s.end(), 5); // this is NOT O(logN) but O(N)
    // for sets use set.lower_bound() function, as it uses tree implementation to traverse
    auto it_set = s.lower_bound(5);
    if (it_set != s.end()) cout << *it_set << endl;
    map<int, int>m;
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int x;
        int y;
        cin >> x >> y;
        m[x] = { y };
    }
    auto it_map = m.lower_bound(3); // works on keys only!
    if (it_map != m.end()) cout << (it_map)->first << " " << it_map->second << endl;
    return 0;
}
```

### Upper Bound

- Always returns the iterator of the first greater element than the current element. Works in the same way as lower bound.
- Returns an iterator to the first element in the range that is greater than the specified value.
- Takes the range of addresses (start: inclusive, end: exclusive) on which the operation needs to be performed, and the value of which the upper bound needs to be found.
- If no element is greater than the specified value, it returns the end iterator of the range.

- Example:

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    map<int, int>m;
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int x;
        int y;
        cin >> x >> y;
        m[x] = { y };
    }

    auto it_map_upper_bound = m.upper_bound(4);
    if (it_map_upper_bound != m.end()) cout << it_map_upper_bound->first << " " << it_map_upper_bound->second << endl;

    return 0;
}
```

### Some inbuilt algorithms and Lambda Functions in C++ STL

- All of them take a range of starting(inclusive) and ending(exclusive) addresses to operate on.

1. min_element() : returns the pointer/iterator of the minimum element in the range.
2. max_element() : returns the pointer/iterator of the maximum element in the range.
3. count() : counts the occurence of an element in the given range and returns the count.
4. find() : returns the iterator/pointer of that element and if not found then returns the iterator/pointer of the next to the last element in the data structure(basically the end iterator/pointer), in the provided range.
5. reverse() : reverses the elements of a data structure(like arrays, vectors and strings) in the provided range.
6. accumulate(): sums the elements in the given range and takes the initial sum as the third argument as well.

- Obviously, in case of arrays, instead of iterators we directly use the variable name(say a) for ranges like this : `sort(a, a+n)`, asssuming that there are 'n' elements in the array.

```cpp
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
```

6. all_of(): returns true only if all the elements satisfy the condition.
7. any_of(): returns true if atleast one of the elements satisfy the condition.
8. none_of(): returns true if none of the elements satisfy the condition.

```cpp
#include <bits/stdc++.h>
using namespace std;

bool is_positive(int x){
    return x>0;
}

int main() {

    vector<int> v = { 2,4,6,7 };
    //using regular function
    cout << all_of(v.begin(), v.end(), is_positive) << endl;

    //using lambda function
    cout << any_of(v.begin(), v.end(), [](int x) {return x > 0;}) << endl;
    cout << none_of(v.begin(), v.end(), [](int x) {return x > 0;}) << endl;

    return 0;
}
```

### Lambda function

- This is a concise way of writing a function and could be assigned to a variable as well, like this:

- Syntax : `[](int a, int b){ return a+b;}`, to call it, write parentheses just to the side of it like this :` [](int a, int b){ return a+b;}()`;
  - `auto sum = [](int a, int b){ return a+b;};`

```cpp
#include <bits/stdc++.h>
using namespace std;


int main() {
    cout << [](int x, int y) {return x + y;}(2, 3) << endl; // calling the anonymous lambda function
    auto sum = [](int x, int y) {return x + y;};
    cout << sum(2, 5) << endl;

    return 0;
}
```

# Data Structures and Algorithms

## Hashing and Pre-Computation

- Formal Definition of hashing: Hashing is a technique used to map data from a large input space to a smaller, fixed-size range of integers (often referred to as "hashes"). `The goal is to efficiently store and retrieve data in a way that allows for quick lookups, insertions, and deletions.` Hashing is commonly used to implement data structures like hash tables, which are `key in solving problems involving frequent queries on large datasets.`

- Formal Definition of Pre-computation : Pre-computation refers to the `process of computing and storing results in advance before they are needed during the actual query or operation phase`. This technique is especially useful in scenarios where the same computation may need to be repeated multiple times.

- Here's an example: We reduced the time complexity by creating a hash array then did the pre-computation(in a frequency array and stored it) till the max size,i.e., 10<sup>5</sup> and simply looked up for the data in our hash vector.

- This reduces the time complexity by a lot, especially for large datasets.

```cpp
#include <bits/stdc++.h>
using namespace std;
/*
Given an array 'a' of N integers. Given Q queries and in each
query given a number X, print the count of that number in array.

Constraints:
1<=N<=10^5
1<=a[i]<=10^7
1<=Q<=10^5
 */

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int q;
    cin >> q;
    // while (q--) // O(q*n) == O(10^10) => this won't run in one second
    // {
    //     int x;
    //     cin >> x;
    //     int ct = 0;
    //     for (int i = 0; i < n; i++) {
    //         if (a[i] == x) {
    //             ct++;
    //         }
    //     }
    //     cout << ct << endl;
    // }

    // Pre-computing the frequencies of the element
    vector<int> freq(1e7 + 10); // hash vector(or array)
    for (int i = 0; i < n; i++) { // O(n)
        freq[a[i]]++; // calculate frequency of each element in advance
    }

    while (q--) { // O(q)
        int x;
        cin >> x;
        cout << freq[x] << endl;
    }

    // Total time complexity = O(n+q)

    return 0;
}
```

### Prefix sum technique of Precomputation

1. Prefix sum on 1D arrays

- Use 1-based indexing the questions of prefix sum
- To find occurences or sums in a range.

```cpp
#include <bits/stdc++.h>
using namespace std;
/*
Given an array 'a' of N integers. Given Q queries and in each query given L
and R, print sum of the array elements from L to R (both incluive).

Constraints:
1<=N<=10^5
1<=a[i]<=10^9
1<=Q<=10^5
1<=L,R<=N
*/

// Use 1-based indexing in case of prefix sum
int main() {
    int N;
    cin >> N;
    vector<int> a(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    // pre-compute the prefix-sum in a pf vector, declare it vector<long long>
    // because of the order of elements of the vector 'a'

    // computing the prefix sum
    vector<long long> pf(N + 1); // 'long long' because of the nature of the elements of vector 'a'
    pf[1] = a[0];
    for (int i = 2; i <= N; i++) {
        pf[i] = pf[i - 1] + a[i];
    }

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << pf[r] - pf[l - 1] << endl;
    }

    // O(N + Q)

    return 0;
}
```

2. Prefix sum on 2D arrays

```cpp
#include <bits/stdc++.h>
using namespace std;

/*
    Given 2D array of N*N integers. Given Q queries and in each query given
    a,b,c and d print sum of square represented by (a,b) as top left point and
    (c,d) as top bottom right point.

    Constraints:
    1<=N<=10^3
    1<=a[i][j]<=10^9
    1<=Q<=10^5
    1<=a,b,c,d<=N
*/

int main() {
    int n;
    cin >> n;
    vector<vector<int>>v(n + 1, vector<int>(n + 1, 0));
    vector<vector<long long>>pf(n + 1, vector<long long>(n + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> v[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            pf[i][j] = v[i][j] + pf[i - 1][j] + pf[i][j - 1] - pf[i - 1][j - 1];
        }
    }

    int q;
    cin >> q;
    while (q--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << pf[c][d] - pf[a - 1][d] - pf[c][b - 1] + pf[a - 1][b - 1] << endl;
    }


    return 0;
}
```

3. [Prefix Sum with a twist](https://www.hackerrank.com/challenges/crush/problem)

```cpp
#include <bits/stdc++.h>
using namespace std;
// L to R addition type problem
int main() {
    int n;
    cin >> n;
    vector<long long> v(n + 1, 0);
    int t;
    cin >> t;
    vector<vector<long long>> q(t, vector<long long>(3));
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> q[i][j];
        }
    }

    // Setting the elements cleverly
    for (int i = 0; i < t; i++) {
        int a = q[i][0], b = q[i][1], k = q[i][2];
        v[a] += k;
        if (b + 1 <= n) v[b + 1] -= k;
    }

    // performing prefix sum to pre-compute the answer
    for (int i = 1; i <= n; i++) {
        v[i] += v[i - 1];
    }

    long long max_el = v[1];
    for (int i = 2; i <= n; i++) {
        if (max_el < v[i]) {
            max_el = v[i];
        }
    }

    cout << max_el;
    return 0;
}

```

4. Prefix Sum and Hashing both

```cpp
#include <bits/stdc++.h>
using namespace std;
// find in the range L to R if the string is palindromic?
/*
Input:
2
5 5
abcec
1 2
2 5
3 5
1 5
1 4
5 5
aabbc
1 2
2 5
3 5
1 5
1 4

Output:
NO
NO
YES
NO
NO
YES
NO
YES
YES
YES


*/
// prefix sum and hashing
int main() {
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        // hashing
        vector<vector<int>>v(s.size() + 1, vector<int>(26, 0));
        for (int i = 0; i < n; i++) {
            v[i + 1][s[i] - 'a']++;
        }
        // prefix sum
        for (int i = 0; i < 26; i++) {
            for (int j = 1; j <= n; j++) {
                v[j][i] += v[j - 1][i];
            }
        }
        while (q--)
        {
            int l, r;
            cin >> l >> r;
            int oddCt = 0;
            for (int i = 0; i < 26; i++) {
                int charCt = v[r][i] - v[l - 1][i];
                if (charCt % 2 != 0) oddCt++;
            }
            if (oddCt > 1) cout << "NO\n";
            else cout << "YES\n";
        }

    }


    return 0;
}




```

## Number Theory

### Factors and Sum of Divisors

&nbsp;&nbsp;&nbsp;&nbsp;x = p<sub>1</sub><sup>n<sub>1</sub></sup> &times;p<sub>2</sub><sup>n<sub>2</sub></sup> &times;...p<sub>t</sub><sup>n<sub>t</sub></sup>, where p<sub>k</sub> is a prime factor of the number x.

- Count of divisors = (n<sub>1</sub> + 1) &times; (n<sub>2</sub>+1) &times; (n<sub>3</sub>+1)... &times; (n<sub>t</sub>+1)
- Sum of divisors = ((p<sub>1</sub><sup>n<sub>1</sub>+1</sup>)/(p<sub>1</sub>-1)) + ((p<sub>2</sub><sup>n<sub>2</sub>+1</sup>)/(p<sub>2</sub>-1)) + ....

1. Finding all the factors of a number, their count and sum as well

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ct = 0;   // count of divisors
    int sum = 0;  // sum of divisors
    /* 1. naive approach : O(N) method
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) cout << i << endl;
    }
    */

    // 2. O(sqrt(n)) method
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            cout << i << " " << n / i << "\n";
            ct++;
            sum += i;
            if (n / i != i) {
                ct++;
                sum += n / i;
            }
        }
    }
    cout << "ct: " << ct << ", sum: " << sum << "\n";


    return 0;
}
```

2. Checking if a number is prime or not

```cpp
#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    bool is_prime = true;
    // 1. O(N) - naive approach
    /* for (int i = 2; i < n; i++) {
        if (n == 1) {
            is_prime = false;
            break;
        }
        if (n % i == 0) {
            is_prime = false;
            break;
        }
    } */

   //2. O(sqrt(N))
    for (int i = 2; i * i <= n; i++) {
        if (n == 1) {
            is_prime = false;
            break;
        }
        if (n % i == 0) {
            is_prime = false;
            break;
        }
    }

    cout << is_prime << "\n";


    return 0;
}
```

3. Finding all the prime factors of a number

```cpp
#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> prime_factors;
    // 1. O(N) approach
    /* for (int i = 2; i <= n; i++) {
        while (n % i == 0) {
            prime_factors.push_back(i);
            n /= i;
        }
    } */

   // 2. O(sqrt(N)) approach
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            prime_factors.push_back(i);
            n /= i;
        }
    }

    if (n > 1) { // the last prime number which would be left will be caught by this
        prime_factors.push_back(n);
    }

    for (int prime : prime_factors) {
        cout << prime << " ";
    }

    return 0;
}
```

### Sieve of Eratostheneses: Finding all the primes in a range

- A form of `pre-computation` in a given range.

```cpp
// pre-compute all the numbers
#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 10;
vector<bool> isPrime(N, 1);

int main() {
    isPrime[0] = isPrime[1] = false;
    // sieve algorithm -> precompute all the primes in the given range
    // O(NloglogN) -> time complexity, smaller than O(logN)
    for (int i = 2; i < N; i++) {
        if (isPrime[i] == true) {
            for (int j = 2 * i; j < N; j += i) {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 1; i < 100; i++) {
        cout << i << ": " << (isPrime[i] == true ? "true" : "false") << "\n";
    }

    return 0;
}
```

## Bit Manipulation

- Number of digits in a binary number = (int)(log<sub>2</sub>(N)) + 1.
- `n & (-n) isolates the rightmost set bit of n. It doesn't give the position but rather a number where only the rightmost set bit of n is set.`

  Example: let n = 10010, then (10010) & (01110) = 00010, here 01110 is the 2's complement(negative) of 10010.

- `rightmost_unset_bit = (~n) & (n + 1). rightmost_unset_bit is a value that has only one bit set at the position of the rightmost unset bit in n.`

```cpp
#include <bits/stdc++.h>
using namespace std;

int setBit(int n) {
    if (n == 0) return 1;

    int rightmost_unset_bit = (~n) & (n + 1);
    return n | rightmost_unset_bit;
}

int main() {
    int n;
    cin >> n;
    cout << setBit(n);
    return 0;
}
```

- n & (n-1) clears the rightmost set bit.

  Example: let n = 10010, then
  (10010) & (10010-1) = (10010) & (10001) = 10000

- (1 << i) & n tells if the ith bit is set in a number or not. If 1-based indexing then (1<<(i-1)) & n would give the same result.

- 1 << i = 2<sup>i</sup>, it would overflow after the 31st bit, as the limit is 2<sup>31</sup>-1. Left shifting a number means multiplying by 2.

- 1 >> i = 2<sup>-i</sup>. Right shifting a number means dividing by 2.

- 1 ^ bit = flipped bit.

  - 1 ^ 0 = 1
  - 1 ^ 1 = 0

- 1 & bit = bit.
  - 1 & 1 = 1
  - 1 & 0 = 0
- 1 | bit = 1
  - 1 | 1 = 1
  - 1 | 0 = 1
- 0 & bit = 0 &rarr; This is used for masking unwanted bits and set them to 0.

- Find sum of set bits upto a number N

```cpp

int countSetBits(int n) {
    int count = 0;
    for (int i = 0; (1 << i) <= n; ++i) {
        int bitMask = (1 << (i + 1)); // Size of full cycles
        int completeCycles = n / bitMask; // Number of complete cycles
        int remaining = n % bitMask; // Remaining numbers after full cycles

        count += completeCycles * (bitMask / 2) + max(0, remaining - (bitMask / 2) + 1);
    }
    return count;
}
```

- Dividing two integers using bit manipulation !!!IMPORTANT!!!

```cpp
#include <bits/stdc++.h>
using namespace std;

int divide(int dividend, int divisor) {
    bool is_negative = (dividend < 0) ^ (divisor < 0);

    if (divisor == -1) {
        if (dividend == INT_MIN) return INT_MAX;
        return -dividend;
    }
    if (dividend == 0)
        return 0;
    if (dividend == divisor)
        return 1;
    if (divisor == 1)
        return dividend;

    long long q = 0;
    long long d1 = abs(divisor);  // divisor
    long long d2 = abs(dividend); // dividend

    // what we need to find is d2/d1

    while (d2 >= d1) {
        long long temp = d1, multiple = 1;
        while (d2 >= (temp << 1)) {
            temp <<= 1;
            multiple <<= 1;
        }
        d2 -= temp;
        q += multiple;
    }

    if (is_negative) {
        q = -q;
    }

    if (q > INT_MAX) {
        return INT_MAX;
    }

    if (q < (INT_MIN)) {
        return INT_MIN;
    }

    return q;
}

int main() {
    int dividend, divisor;
    cin >> dividend >> divisor;
    cout << divide(dividend, divisor);

    return 0;
}
```

- XOR from L To R, both inclusive, i.e., [L,R]

```cpp
#include <bits/stdc++.h>
using namespace std;

int xorUpto(int a) { // xor from 0 to a(both inclusive)
    switch (a % 4) {
    case 0: return a;
    case 1: return 1;
    case 2: return a + 1;
    case 3: return 0;
    }
    return 0;
}

int xor_from_l_to_r(int l, int r) { // both inclusive
    return xorUpto(l - 1) ^ xorUpto(r);
}


int main() {
    int l, r;
    cin >> l >> r;
    cout << xor_from_l_to_r(l, r);
    return 0;
}
```

## Two Pointer and Sliding Window

1. Whenever you get the problem of finding max/min substring think of two pointer and sliding window approach.
2. These algos are more of a constructive approach and the only thing which remains constant is the window and it keeps moving across the string.
3. How the window is moved, depends on the problem.

- We start out with an empty window, i.e., `l and r` would be at the same position then we keep expanding the window until some condition is violated and at that point we simply move the window ahead, i.e., move `l` to a new position.

- `l`: moves the window, `r` expands the window.

### Examples:

1. [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/description/)

```cpp
#include <bits/stdc++.h>
using namespace std;


int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int>m(256, -1); // hash array for 250 characters
    int l = 0, r = 0;
    int max_length = 0;
    while (r < n) {
        int length = 0;

        if (m[s[r]] != -1) { // check if the character is already in the hash array
            if (m[s[r]] >= l) { // check if that character is in our window
                l = m[s[r]] + 1; // move the window if it is in the window

            }
        }
        m[s[r]] = r; //re-assign new value to the position of that character
        length = r - l + 1;
        max_length = max(max_length, length);
        r++;
    }
    cout << "max length: " << max_length;
    return 0;
}
```

## Recursion

### When to apply recursion?

- It breaks large problems into smaller ones, and once we devise a solution for the smaller one then it eventually adds upto the solution of large problems.
- To explore all the possibilities &rarr; use recursion.
- Count the number of ways.
- Multiple ways of doing something, then minimum or maximum number of ways are asked.

- Try to write the function in its own terms.
  For example : digit_sum(num)

  Let's say, num = 1234.

  `digit_sum(num) = last_digit + digit_sum(num_with_its_last_digit_removed);`

  digit_sum(1234) = 4 + digit_sum(123);

  digit_sum(123) = 3 + digit_sum(12);

  digit_sum(12) = 2 + digit_sum(1);

  digit_sum(1) = 1 + digit_sum(0);

  digit_sum(0) = 0; -> base condition to terminate.

Hence, `digit_sum(num) = (num%10) + digit_sum(num/10)` -> from the above pattern.

### Example code :

```cpp
#include <bits/stdc++.h>
using namespace std;

int digit_sum(int num)
{
    if (num == 0)
        return 0;
    return (num % 10) + digit_sum(num / 10);
}

int main()
{
    int num;
    cin >> num;
    cout << "Hello world";
    cout << num;
    // this is the recursive part when you go down the tree
    digit_sum(num);
    // this is the part when you come back up in the tree
    return 0;
}
```

### Time Complexity of Recursion

1. `Compute the total number of function calls.`
2. `Compute the time complexity of each function.`

- In the above example, for each digit the function call happens once, so the total number of function calls = number of digits(say, n). In each function call, the operations have O(1) time complexity as there's no loop, rather just a simple if statement and a function call.

  Hence the total time complexity is given by : O(1 \* n) = O(n)

- If the number is taken to be 'n', then the number of digits will be: log(n) + 1. Then the time complexity will be : O(log(n) \* 1) = O(log(n)).

- Less significant terms and constants are ignored in the Big-O notation. (That's why O(log(n)) in the above example.)

#### Backtracking in Recursion

- Backtracking is simply used to maintain the state of recursion, i.e., for the same function when the recursion comes back up to it from the stack then the variables in the body/parameters need to be same.

- For example, when we pass some string/array using reference then the actual string/array is being modified in each function call hence when the recursion comes back up in the tree to run some code below the call then the actual string/array for that function would have been modified which would result in unexpected behavior. So to reset it to the original state, i.e., to the state in which the recursion started for that string/array we revert the changes.

This preserves the actual state of the recursion and allows us to traverse through the recursive tree properly.

- Maze traversal is the best example for this.

- Or when we pass some array/string/variable(by reference) and we need to come back up in the function to perform some operation on it then we might need to use backtracking if the operations are needed to be performed on the previous version of the variable, i.e., the one with which the recursion was called.

- `It's nothing different from recursion, just a fancy name.`

## Patterns In Recursion

- Variable number of recursive calls at a level &rarr; use for loop and put the recursion inside it.

- Use the `void` return type to explore all the possibilities.

- Return 1 or 0 if you want to count then add all the recursive calls and return it. Return 0 when the condition isn't satisified and if it's satisified return 1.

- Return true or false if you need to break the recursion after the condition is once satisfied. Return true for satisified conditions else return false.

1. Unique Elements in an array: Use the take/not-take technique, no for loop and terminate the recursion using the base case yourself.

   - [Taking the same element unlimited number of times](#combination-sum-taking-the-same-element-multiple-times)
   - [Taking the element only once](#combination-sum-variation-taking-an-element-just-once)

2. Duplicate Elements in an array: Sort the array, use the for loop and inside it put the recursion, for loop will automatically do the take/not-take and will implicitly terminate so we don't necessarily need a base case to terminate the recursion rather terminate when the conditions are satisfied.

   - [Taking the element only once and skipping the duplicates](#combination-sum-ii-taking-an-element-just-once)
   - Take an element unlimited number of times
     Remove the duplicate ones and solve it like [Combination Sum I](#combination-sum-taking-the-same-element-multiple-times)

3. Permutations: We use the for loop method because of the variable number of choices to start with and put the recursion inside the for loop which eventually picks up the elements provided the same element hasn't been picked already. If there are duplicate elements use the way taught in [Combination Sum II](#combination-sum-ii-taking-an-element-just-once) and add the `f[i-1]==0` along with it.

### Combination Sum: Taking the same element multiple times

- Remember this pattern that when we have to pick elements from an array which consists of unique elements then we use the `pick/not-pick` method without the for loop!

```cpp
class Solution {
private:
    void solve(vector<int>& candidates, int target, vector<vector<int>>& ans,
               vector<int>& current, int n, int i) {
        if (i >= n) {
            if (target == 0) {
                ans.push_back(current);
            }
            return;
        }

        // take
        if (target > 0) { // important line
            current.push_back(candidates[i]);
            solve(candidates, target - candidates[i], ans, current, n, i);
            current.pop_back();
        }

        // not take
        solve(candidates, target, ans, current, n, i + 1);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> current;
        int n = candidates.size();
        solve(candidates, target, ans, current, n, 0);
        return ans;
    }
};
```

- In the above question we stop when the target becomes negative, i.e, we can take the elements as many times as we want but if the target becomes negative we stop because then no combination of it would sum upto target.

### Combination Sum Variation: Taking an element just once

```cpp
#include <bits/stdc++.h>
using namespace std;
void solve(vector<int>& candidates, int target, vector<vector<int>>& ans,
               vector<int>& current, int n, int i) {
        if (i >= n) {
            if (target == 0) {
                ans.push_back(current);
            }
            return;
        }

        // take
        if (target > 0) { // important line
            current.push_back(candidates[i]);
            solve(candidates, target - candidates[i], ans, current, n, i+1);
            current.pop_back();
        }

        // not take
        solve(candidates, target, ans, current, n, i + 1);
    }

int main(){
    int n, target;
    cin >> n >> target;
    vector<int> ds;
    vector<int> candidates(n);
    for(int i=0; i<n; i++){
        cin >> candidates[i];
    }
    vector<<vector<int>> ans;
    solve(candidates, target, ans, ds, n, 0);
    return 0;
}
```

### Combination sum II: Taking an element just once!

- First sort the original array.

- Remember this pattern, where when we have to choose `non-duplicate` elements from an array having duplicate elements ofcourse, then we use for loop along with the `pick/not-pick` technique and put the recursion inside it, as done below.

- `No explicit base condition`(like ind>=n) because the for loop does it implicitly anyway.

```cpp
#include <bits/stdc++.h>
using namespace std;

void f(int ind, int target, int& n, vector<int>& ds,
    vector<vector<int>>& ans, vector<int>& v) {
    if (target == 0) {
        ans.push_back(ds);
        return;
    }

    // recursion inside the for loop and we moved ahead as we can't pick the same element unlimited number of times
    for (int i = ind; i < n; i++) {
        if (i > ind && v[i] == v[i - 1])
            continue;
        if (v[i] > target)
            break;
        ds.push_back(v[i]);
        f(i + 1, target - v[i], n, ds, ans, v);
        ds.pop_back();
    }
}


int main() {
    int n, target;
    cin >> n, target;

    vector<int> v;
    vector<vector<int>> ans;
    vector<int> current;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end()); // sort the original array

    f(0, target, n, current, ans, v);

    return 0;
}
```

- We stop when the target becomes 0, that means we got the answer and we either store it or print it. To check for the duplicate elements we resort back to the for loop and `if(i>ind && v[i]==v[i-1])` we skip that iteration, if the target becomes negative/ `v[i]>target` we can `break/return` the/from the loop.

### Subsets I: Printing the subsets of an array with unique elements

- Similar to Combination Sum I

```cpp
#include <bits/stdc++.h>
using namespace std;

void f(int ind, int sum, int n, vector<int>& v, vector<int>& current) {
    if (ind >= n) {
        if (current.size() == 0) cout << "{}";
        for (auto& it : current) {
            cout << it << " ";
        }
        cout << "\n" << "sum: " << sum << "\n \n";
        return;
    }

    current.push_back(v[ind]);
    f(ind + 1, sum + v[ind], n, v, current);
    current.pop_back();

    f(ind + 1, sum, n, v, current);
}

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    vector<int> current;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    f(0, 0, n, v, current);

    return 0;
}
```

### Subsets II: Ignoring the dupilcates and printing all the subsets

- Similar to Combination Sum II

- Here we don't need fully formed subsets till `n` rather we want all the unique subsets, that's why `no explicit base condition` because the for loop does it implicitly anyway.

```cpp
#include <bits/stdc++.h>
using namespace std;

void f(int ind, int n, vector<int>& v, vector<int>& current) {
    // Include the current subset in the output immediately
    for (auto& it : current) {
        cout << it << " ";
    }
    cout << "\n";

    // Explore further elements starting from the current index
    for (int i = ind; i < n; i++) {
        if (i > ind && v[i] == v[i - 1]) {
            continue;  // Skip duplicates
        }
        current.push_back(v[i]);
        f(i + 1, n, v, current);
        current.pop_back();
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    vector<int> current;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());  // Sort to handle duplicates
    f(0, n, v, current);

    return 0;
}

```

### Permutations I: Array has unique elements

- Approach 1
  - We go until we have all the elements in the data structure.
  - Remember this pattern and there's for loop and inside it the recursion because of variable number of function calls at each step.
  - `i=0` in each case because again for every element previous elements need to be considered.

```cpp
#include <bits/stdc++.h>
using namespace std;

void f(int ind, int n, vector<int>& v, int freq[], vector<int>& ds) {
    if (ds.size() == n) { // we will go till we have all the three elements
        for (auto& i : ds) {
            cout << i << " ";
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < n; i++) { // for each element I have to check from i=0 only
    // like in case of [1,2,3] if we take 2 first then [2, 1, 3] is also possible, hence we need i=0.
        if (!freq[i]) {
            freq[i] = 1;
            ds.push_back(v[i]);
            f(i + 1, n, v, freq, ds);
            ds.pop_back();
            freq[i] = 0;
        }
    }


}

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    vector<int> current;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int freq[n] = { 0 };
    f(0, n, v, freq, current);

    return 0;
}

```

### Permutations II: Skipping the duplicate elements

- We skip it just like we did it in Subets II and Combination Sum II.

```cpp
#include <bits/stdc++.h>
using namespace std;

void permutations(int j, vector<int>& v, vector<int>& ds, int f[]) {
    if (ds.size() == v.size()) {
        for (auto&& it : ds) {
            cout << it << " ";
        }
        cout << "\n";
    }

    for (int i = 0; i < v.size(); i++) {
        if (i > 0 && v[i] == v[i - 1] && f[i - 1] == 0) {
            continue;
        }
        if (f[i] != 1) {
            f[i] = 1;
            ds.push_back(v[i]);
            permutations(i + 1, v, ds, f);
            ds.pop_back();
            f[i] = 0;
        }
    }

}


int main() {
    vector<int> v = { 1,2,2 };
    vector<int> ds;
    int f[v.size()] = { 0 };
    permutations(0, v, ds, f);
    return 0;
}
```

## Graphs : Contd. after the Java notes, but in C++

### What is a graph?

- Collection of nodes/vertices and/or edges.
- Generally in questions, N : Number of vertices and M: Number of edges.
- And in M lines we are given the edges between nodes(will make more sense in the graph representation section).

Example:

        6 9 -> N = 6, M = 9
        In rest of the M lines, we are given the configuration of nodes
        1 3
        1 5
        3 5
        3 4
        3 6
        3 2
        2 6
        4 6
        5 6

### Types of graph

1. Undirected : no arrows to a node, i.e., no bi-directional edge.
2. Directed : edges have arrows, and graphs can be traversed in a specific direction.
3. Acyclic : graphs with no cycles.
4. Cyclic : graphs with cycles.

### What are trees?

- Graphs with no cycles. Acyclic undirected graphs are called trees as well.
- Number of edges(m) = Number of nodes(n) - 1.
- Root node: Could be any node, we consider rest of the tree hanging from it.
- Leaf node: Nodes without any children.
- Depth of a node: Distance of a node from the root node.
- Height of a node: Max number of edges starting from any leaf node to that node.
- LCA: The first common node of 2 or more nodes is called lowest common ancestor.

### What are connected components? (Related to graphs)

- For undirected graph:
  - If from one node, every other node in that component can be traversed, then it's connected component.
  - Sometimes, multiple connected components together are called a forest, its a graph too but with multiple connected components.
  - Number of connected Components : The nummber of time DFS runs.
- For directed graph: Could be cyclic or acyclic depending on the direction
  - We define strongly connected components here, instead of just connected components.
  - Strongly connected component : It should be possible to reach at every node from the starting node.

### Graph Representation

- Input:

        6 9
        1 3
        1 5
        3 5
        3 4
        3 6
        3 2
        2 6
        4 6
        5 6

1. Adjacency Matrix
2. Adjacency List &rarr; mostly used because of less space complexity

   1. Adjacency Matrix

   - Make a matrix of n\*n(n = number of vertices, m = number of edges).
   - If 1-based graph then make (n+1)\*(n+1).
   - a[i][j] = 1 && a[j][i] = 1, if i and j are connected, else it's 0 &rarr; for undirected graph.
   - a[i][j] = 1, if i and j are connected for directed ones(depending on the direction)
   - if edges have weights, a[i][j] = w &rarr; w is the weight.
   - Can get and edge and weight between edges in O(1)

```cpp
#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    // adjacency matrix -> too much space complexity(O(N^2))
    vector<vector<int>>graph(n + 1, vector<int>(n + 1, 0)); // initialized a 2D vector
    for (int i = 0; i < m; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1][v2] = 1;
        graph[v2][v1] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
```

- Output of adjacency matrix:

        0 0 1 0 1 0
        0 0 1 0 0 1
        1 1 0 1 1 1
        0 0 1 0 0 1
        1 0 1 0 0 1
        0 1 1 1 1 0

  2. Adjacency List

  - Make number of lists(arrays/vectors) = number of nodes(+1 if 1-based).
  - In each list store, the nod with which it is connected.
  - Space Complexity = O(V+2E) ~ O(V+E)
  - To find weight and edge, we need to run a loop, in O(N).

1. Unweighted graph

```cpp
#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    // adjacency list : O(V+E)
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    // N = 10^5, M<= 10^7

    for (const auto& row : graph) {
        for (const auto& el : row) {
            cout << el << " ";
        }
        cout << "\n";
    }

    return 0;
}
```

2. Weighted Graph

- Input: last elements are the weights

        6 9
        1 3 4
        1 5 3
        3 5 2
        3 4 7
        3 6 8
        3 2 9
        2 6 1
        4 6 2
        5 6 3

```cpp
#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    // adjacency list : O(V+E)
    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt;
        graph[v1].push_back({ v2, wt });
        graph[v2].push_back({ v1, wt });
    }

    // N = 10^5, M<= 10^7

    for (const auto& row : graph) {
        for (const auto& el : row) {
            cout << "{node: " << el.first << " wt:" << el.second << "}, ";
        }
        cout << "\n";
    }

    return 0;
}
```

- Output:

        {node: 3 wt:4}, {node: 5 wt:3},
        {node: 3 wt:9}, {node: 6 wt:1},
        {node: 1 wt:4}, {node: 5 wt:2}, {node: 4 wt:7}, {node: 6 wt:8},{node: 2 wt:9},
        {node: 3 wt:7}, {node: 6 wt:2},
        {node: 1 wt:3}, {node: 3 wt:2}, {node: 6 wt:3},
        {node: 3 wt:8}, {node: 2 wt:1}, {node: 4 wt:2}, {node: 5 wt:3},

### Significance of Visited Array

- Helps us in traversing each and every node of a forest/graph.
- Prevents infinite loops by making the node be visited only once.
- `Length of visited array = Length of adjacency list = Length of Adjacency Matrix = Number of nodes(if 0-based indexed graph) or Number of nodes+1(if 1-based indexed graph)`

### Depth First Search(DFS)

- `Goes in-depth of the graph/tree and visits/explores every node.`
- `We do come back to the node from which we started.`
- `Even if a node has been visited by some other node already, but it would be checked out by the parent node again, i.e., suppose 3 was visited by 2 already, but if 3 is a child of 1, it will atleast be checked out by 1 and then it'll do nothing as it will be visited already.`
- Uses recursion.
- Used to find the number of connected components in a graph.
- Used to find cycles in a graph.
- Time Complexity: O((Number of vertices) + 2\*(Number Of Edges)) ~ O(N+M)
- Code: Do remember the four areas and their significance in the code

```cpp
#include <bits/stdc++.h>
using namespace std;


void dfs(int vertex, vector<int> g[], vector<bool>& vis) {
    // take action on vertex after entering the vertex
    vis[vertex] = true;
    cout << vertex << "\n";
    for (int child : g[vertex]) {
        // take action on child before entering the child node(haven't called dfs yet)
        cout << "par: " << vertex << ", child: " << child << "\n";
        if (vis[child]) continue;
        dfs(child, g, vis);
        // take action on child after exiting the child node(called dfs on child)
    }
    // take action on vertex before exiting the vertex
}



int main() {
    int n, m;
    cin >> n >> m;
    vector<int> g[n + 1];
    vector<bool>vis(n + 1, false);
    for (int i = 0; i < m; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    for (int i = 0; i < n + 1; i++) {
        if (vis[i]) continue;
        dfs(i, g, vis);
    }

    return 0;
}
```

- Output:

        1
        par: 1, child: 3
        3
        par: 3, child: 1
        par: 3, child: 5
        5
        par: 5, child: 1
        par: 5, child: 3
        par: 5, child: 6
        6
        par: 6, child: 3
        par: 6, child: 2
        2
        par: 2, child: 3
        par: 2, child: 6
        par: 6, child: 4
        4
        par: 4, child: 3
        par: 4, child: 6
        par: 6, child: 5
        par: 3, child: 4
        par: 3, child: 6
        par: 3, child: 2
        par: 1, child: 5

#### Finding Number of Connected Components using DFS

- Input:

        8 5
        1 2
        2 3
        2 4
        3 5
        6 7

- Output : 3

```cpp
#include <bits/stdc++.h>
using namespace std;


void dfs(int vertex, vector<int> g[], vector<bool>& vis) {
    // take action on vertex after entering the vertex
    vis[vertex] = true;
    for (int child : g[vertex]) {
        // take action on child before entering the child node(haven't called dfs yet)
        if (vis[child]) continue;
        dfs(child, g, vis);
        // take action on child after exiting the child node(called dfs on child)
    }
    // take action on vertex before exiting the vertex
}



int main() {
    int n, m;
    cin >> n >> m;
    vector<int> g[n + 1];
    vector<bool>vis(n + 1, false);
    for (int i = 0; i < m; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    int count = 0;
    for (int i = 1; i < n + 1; i++) {
        if (vis[i]) continue;
        count++;
        dfs(i, g, vis);
    }

    cout << count << "\n";

    return 0;
}
```

### Storing the connected components

```cpp
#include <bits/stdc++.h>
using namespace std;


void dfs(int vertex, vector<int> g[], vector<bool>& vis, vector<int>& ccc) {
    // take action on vertex after entering the vertex
    vis[vertex] = true;
    ccc.push_back(vertex);
    for (int child : g[vertex]) {
        // take action on child before entering the child node(haven't called dfs yet)
        if (vis[child]) continue;
        dfs(child, g, vis, ccc);
        // take action on child after exiting the child node(called dfs on child)
    }
    // take action on vertex before exiting the vertex
}



int main() {
    int n, m;
    cin >> n >> m;
    vector<int> g[n + 1];
    vector<bool>vis(n + 1, false);
    vector<vector<int>> cc;
    for (int i = 0; i < m; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    int count = 0;
    for (int i = 1; i < n + 1; i++) {
        if (vis[i]) continue;
        vector<int> ccc; // initialize a new current connected component vector
        count++;
        dfs(i, g, vis, ccc);
        cc.push_back(ccc); // push it back after the dfs completes for each connected component
    }

    for (auto& row : cc) {
        for (auto& el : row) {
            cout << el << " ";
        }
        cout << "\n";
    }

    return 0;
}
```

- Output:
  1 2 3 5 4
  6 7
  8

### Detecting cycles using DFS

- If there's a cycle, we reach a node which is already visited but it is not the parent node from which we came from.

```cpp
// Cycle detection
/*
If there's a cycle, we reach a node which is already visited but it is not the
parent node from which we came from.
*/
#include <bits/stdc++.h>
using namespace std;

bool dfs(int v, int par, vector<int>g[], vector<bool>& vis) {
    vis[v] = true;
    bool does_loop_exist = false;
    for (int child : g[v]) {
        if (vis[child] && child == par) continue;
        if (vis[child]) {
            return true;
        };
        does_loop_exist |= dfs(child, v, g, vis);
    }
    return does_loop_exist;
}


int main() {
    int n, m;
    cin >> n >> m;
    vector<int>g[n + 1];
    for (int i = 0; i < m; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    vector<bool>vis(n + 1, false);
    for (int i = 0; i < vis.size(); i++) {
        if (vis[i]) continue;
        if (dfs(i, 0, g, vis)) {
            cout << "true" << "\n";
            return 0;
        };
    }

    cout << "false" << "\n";

    return 0;
}
```

### Graph Matrix Problems: [Flood Fill Problem](https://leetcode.com/problems/flood-fill/description/)

- Assume all 1's to be the nodes of a graph and that way we'll have components.
- DFS needs to be done in either 4 directions or 8(including diagonals).

```cpp
#include <bits/stdc++.h>
using namespace std;

void dfs(int i, int j, int initialColor, int newColor, vector<vector<int>>& image) {
    int n = image.size();
    int m = image[0].size();
    if (i < 0 || j < 0) return;
    if (i >= n || j >= m) return;
    if (image[i][j] != initialColor) return;

    image[i][j] = newColor;

    dfs(i - 1, j, initialColor, newColor, image);
    dfs(i + 1, j, initialColor, newColor, image);
    dfs(i, j - 1, initialColor, newColor, image);
    dfs(i, j + 1, initialColor, newColor, image);
}


vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int initialColor = image[sr][sc];
    if (initialColor != newColor)
        dfs(sr, sc, initialColor, newColor, image);
    return image;
}


int main() {
    // Flood fill


    return 0;
}
```

### [Number of Islands](https://leetcode.com/problems/number-of-islands/)

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int i,int j,  vector<vector<char>>&g, vector<vector<bool>>&vis){
        if(i<0 || j<0 || i>= g.size() || j>= g[0].size()|| g[i][j]=='0'||vis[i][j]) return;
        vis[i][j] = true;
        dfs(i+1, j, g, vis);
        dfs(i-1, j, g, vis);
        dfs(i, j+1, g, vis);
        dfs(i, j-1, g, vis);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>>vis(m, vector<bool>(n, false));
        int count = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    count++;
                    dfs(i, j, grid, vis);
                }
            }
        }

        return count;
    }

};

int main(){
    return 0;
}
```

### Height and Depth of a tree

- Height is calculated when coming up in the tree and depth is calculated when going down the tree.

```cpp
#include <bits/stdc++.h>
using namespace std;

void dfs(int v, int par, vector<vector<int>>& g, vector<int>& depth, vector<int>& height) {

    // going down into the vertex
    for (int child : g[v]) {
        // going down into the child
        if (child == par) continue;
        depth[child] = depth[v] + 1;
        dfs(child, v, g, depth, height);
        height[v] = max(height[child] + 1, height[v]);
        // coming up from the child
    }
    // coming up from the vertex
}


int main() {
    int n;
    cin >> n;
    vector<vector<int>>graph(n + 1);

    vector<int> depth(n + 1, 0);
    vector<int> height(n + 1);


    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    dfs(1, 0, graph, depth, height);

    for (int i = 1; i <= n; i++) {
        cout << depth[i] << " " << height[i] << "\n";
    }


    return 0;
}
```

### Precomputation in Trees

- Precomputation happens when you come back up from the child because you need the children's value first.

1. Sum of the subtree and even number count

```cpp
#include <bits/stdc++.h>
using namespace std;

void dfs(int v, int par, vector<vector<int>>& g, vector<int>& subtree_sum, vector<int>& even_ct) {
    // take action while going down the vertex
    subtree_sum[v] += v;
    if (v % 2 == 0) even_ct[v]++;
    for (int child : g[v]) {
        if (child == par) continue;
    // take action while going down the child
        dfs(child, v, g, subtree_sum, even_ct);
        subtree_sum[v] += subtree_sum[child];
        even_ct[v] += even_ct[child];
    // take action while coming up from the child
    }
    // take action while coming up from the vertex
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>>g(n + 1);

    for (int i = 1; i <= n - 1; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<int> subtree_sum(n + 1);
    vector<int> even_ct(n + 1);
    dfs(1, 0, g, subtree_sum, even_ct);
    for (int i = 1; i <= n; i++) {
        cout << subtree_sum[i] << " " << even_ct[i] << "\n";
    }
    return 0;
}
```

### LCA of two nodes in a tree

- Store the parents in a parents array and then using that parents array climb back to the root node and store the path of nodes from root node and then simply traverse through both the path array and wherever the equality the node just before it is the LCA.

```cpp
#include <bits/stdc++.h>
using namespace std;


void dfs(int v, int p, vector<vector<int>>& g, vector<int>& par) {
    par[v] = p;
    for (int c : g[v]) {
        if (c == p) continue;
        dfs(c, v, g, par);
    }
}

vector<int> path(int v, vector<int>& par) {
    vector<int> p;
    while (true) {
        if (v == -1) break;
        p.push_back(v);
        v = par[v];
    }
    reverse(p.begin(), p.end());
    return p;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>>g(n + 1);
    vector<int> par(n + 1, -1);
    for (int i = 0; i < n - 1; i++) {
        int x, y; cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    // take any 2 nodes for their LCA, suppose 2 and 12 -> their LCA is 2
    dfs(1, -1, g, par);

    vector<int>p1 = path(12, par);
    vector<int>p2 = path(2, par);

    for (auto& it : p1) {
        cout << it << " ";
    }
    cout << "\n";
    
    for (auto& it : p2) {
        cout << it << " ";
    }
    cout << "\n";

    int LCA = -1;
    for (int i = 0; i < n-1; i++) {
        if (p1[i] != p2[i]) break;
        LCA = p1[i];
    }

    cout << LCA;
    return 0;
}
```

## Dynamic Programming

- Recursion &rarr; Memoization(for time complexity optimization) &rarr; Tabulation(for eliminating space complexity of the stack space) &rarr; Space Optimization to O(1)
- Overlapping sub-problems: we store(`memoize`) the results of sub-problems in a map/table and then simply retrieve it, when they overlap.
- Memoization: Top&rarr;Down &rarr; build from the top(required solution) to the base case
- Tabulation: Bottom&rarr;up &rarr; build from base case till the required solution
- Space Optimization: Eliminating the `dp` array altogether and make it O(1).
  - If there is (index-1) and (index-2) involved, we can always optimize the space.

### Fibonacci Numbers

- Recursive way : Time Complexity &rarr; O(2<sup>N</sup>), Space Complexity &rarr; O(N)

```cpp
#include <bits/stdc++.h>
using namespace std;

int fibo(int n) {
    // recursion
    if (n < 2) {
        return n;
    }
    return fibo(n - 1) + fibo(n - 2); // recurrence relation
}


int main() {

    cout << fibo(4) << "\n";
    return 0;
}
```

- Memoization: Time Complexity &rarr; O(N), Space Complexity &rarr; O(2N) = Stack Space + Array Space

```cpp
#include <bits/stdc++.h>
using namespace std;

// memoization: Time Complexity -> O(N), Space Complexity -> O(2N) = Stack Space + Array Space
int f_memo(int n, vector<int>& dp) {
    if (n <= 1) {
        return n;
    }
    if (dp[n] != -1) return dp[n];
    return dp[n] = f_memo(n - 1, dp) + f_memo(n - 2, dp);
}

int main() {
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    cout << f_memo(n, dp) << "\n";



    return 0;
}
```

- Tabulation: Eliminating stack space in this case
  - Time Complexity &rarr; O(N), Space Complexity &rarr; O(N) = Array Space
  - `Convert the recurrence relation from f(n-1) + f(n-2)` &rarr; `dp[i-1] + dp[i-2].`

```cpp
#include <bits/stdc++.h>
using namespace std;


//tabulation: Time Complexity -> O(N), Space Complexity -> O(N) = Array Space
int f_tabulated(int n, vector<int>& dp) {
    dp[0] = 0; dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main() {
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    cout << f_tabulated(n, dp);

    return 0;
}
```

- Making the space complexity = O(1), by using `prev`, `prev2` and `curi` pointers &rarr; Remember this pattern as it will be used or its variations would be used at many places

```cpp
#include <bits/stdc++.h>
using namespace std;

// space optimization: Time Complexity -> O(N), Space Complexity -> O(1)
int f_space_optimized(int n) {
    int prev2 = 0, prev = 1;
    if (n < 2) return n;
    for (int i = 2; i <= n; i++) {
        int curi = prev2 + prev;
        prev2 = prev;
        prev = curi;
    }
    return prev;
}

int main() {
    int n;
    cin >> n;
    cout << f_space_optimized(n) << "\n";

    return 0;
}

```

### How to identify a DP/Recursion question?

1. Count the number of ways
2. Multiple ways of doing something, then minimum or maximum number of ways are asked

Recursion helps you explore all the possibilities.

## How to write recurrence relations in an easy way?

1. Try to represent the problem in terms of indices(even if there is no array).
2. Do all possible things on that index according to the problem statement.
3. Think of edge cases.
4. If you need to do the following:
   - Count all ways: Sum up all the things
   - Min(of all things): Find Min
   - Max(of all things): Find Max

- Example 1: [Climbing Stairs](https://leetcode.com/problems/climbing-stairs/description/)

```cpp
#include <bits/stdc++.h>
using namespace std;

// this is the recursive way(btw it looks like fibonacci)
int climb_stairs(int i) { // we'll jump down
    if (i == 0) return 1;
    // however, what if i=1, then we'll need to handle the edge case of i = 1
    if (i == 1) return 1;
    int left = climb_stairs(i - 1);
    int right = climb_stairs(i - 2);

    return left + right;

}

// let's memoize it
int f(int i, vector<int>& dp) {
    if (i == 0) return 1;
    if (i == 1) return 1;
    if (dp[i] != -1) return dp[i];
    int left = f(i - 1, dp);
    int right = f(i - 2, dp);

    return dp[i] = left + right;
}

// let's tabulate this
int t(int n, vector<int>& dp) { // size of dp vector would be n+1, for 1-based indexing in this case
    if (n == 0) return 1;
    if (n == 1) return 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

//let's do space optimization
int s(int n) {
    if (n == 0) return 1;
    if (n == 1) return 1;
    int prev = 1, prev2 = 1;
    for (int i = 0; i <= n; i++) {
        int curi = prev2 + prev;
        prev2 = prev;
        prev = curi;
    }

    return prev;
}


int main() {
    // Represent the problem in terms of indices.
    // We'll consider the stairs to be indices from 0 to n.
    // Then either we can jump 1 step or 2 steps -> the things we can do with the index.

    return 0;
}
```

- Example 2: [Frog Jump](https://www.geeksforgeeks.org/problems/geek-jump/1)
  - If there is (index-1) and (index-2) involved, we can always optimize the space.

```cpp
#include <bits/stdc++.h>
using namespace std;

int min_energy_recursive(int ind, vector<int>& heights) {
    if (ind == 0) return 0;
    if (ind == 1) return abs(heights[1] - heights[0]);
    int left = min_energy_recursive(ind - 1, heights) + abs(heights[ind] - heights[ind - 1]);
    int right = min_energy_recursive(ind - 2, heights) + abs(heights[ind] - heights[ind - 2]);

    return (left, right);
}


int min_energy_dp(int ind, vector<int>& dp, vector<int>& heights) {
    if (ind == 0) return 0;
    if (ind == 1) return abs(heights[1] - heights[0]);
    if (dp[ind] != -1) return dp[ind];
    int left = min_energy_dp(ind - 1, dp, heights) + abs(heights[ind] - heights[ind - 1]);
    int right = min_energy_dp(ind - 2, dp, heights) + abs(heights[ind] - heights[ind - 2]);

    return dp[ind] = min(left, right);

}

int min_energy_tabulated(int ind, vector<int>& dp, vector<int>& heights) {
    if (ind == 0) return 0;
    if (ind == 1) return abs(heights[1] - heights[0]);
    dp[0] = 0; dp[1] = abs(heights[1] - heights[0]);
    for (int i = 2; i <= ind; i++) {
        dp[i] = min(dp[i - 1] + abs(heights[i] - heights[i - 1]), dp[i - 2] + abs(heights[i] - heights[i - 2]));
    }
    return dp[ind];
}

int min_energy_space_optimized(int ind, vector<int>& heights) {
    if (ind == 0) return 0;
    if (ind == 1) return abs(heights[1] - heights[0]);
    int prev = abs(heights[1] - heights[0]), prev2 = 0;
    for (int i = 2; i <= ind; i++) {
        int curi = min(prev + abs(heights[i] - heights[i - 1]), prev2 + abs(heights[i] - heights[i - 2]));
        prev2 = prev;
        prev = curi;
    }
    return prev;
}

int main() {
   // Express the question in terms of an index
   // Then do everything with the index as per the question
   // Think of the edge cases, like ind == 1, in this case.
   // Then return the minimum of the things you did on the index
    return 0;
}
```

- Example 3: [Frog Jump with K steps](https://atcoder.jp/contests/dp/tasks/dp_b)
- It demonstrates how 2 loops are required in the tabulated format.

```cpp
#include <bits/stdc++.h>
using namespace std;

int jump_with_k_steps(int n, int k, vector<int>& arr) {
    if (n == 0) return 0;
    int min_steps = INT_MAX;
    for (int i = 1; i <= k; i++) {
        if (n - i >= 0) {
            int jump = jump_with_k_steps(n - i, k, arr);
            min_steps = (min_steps, jump);
        }
    }
    return min_steps;
}

int jump_with_k_steps_memoized(int i, int k, vector<int>& arr, vector<int>& dp) {
    if (i == 0) return 0;
    if (dp[i] != -1) return dp[i];
    int min_steps = INT_MAX;
    for (int j = 1; j <= k; j++) {
        if (i - j >= 0) {
            int jump = jump_with_k_steps_memoized(i - j, k, arr, dp) + abs(arr[i - j] - arr[i]);
            min_steps = (min_steps, jump);
        }
    }
    return dp[i] = min_steps;
}

int jump_with_k_steps_tabulated(int n, int k, vector<int>& arr, vector<int>& dp) {
    if (n == 0) return 0;
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        int min_steps = INT_MAX;
        for (int j = 1; j <= k; j++) {
            if (i - j >= 0) {
                int jump = dp[i - j] + abs(arr[i - j] - arr[i]);
                min_steps = min(jump, min_steps);
            }
        }
        dp[i] = min_steps;
    }

    return dp[n];
}


int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> dp(n + 1, -1);
    cout << jump_with_k_steps_tabulated(n - 1, k, arr, dp);
    return 0;
}
```
