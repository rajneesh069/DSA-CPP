# C++ Standard Template Library(STL)

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
- Range based loops can iterate over the elements directly.
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

### Ordered Maps: Insertion, Deletion and Accessing time is O(logN)

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

### Unordered Maps : Average Insertion, Deletion and Accessing time is O(1)

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

### Ordered Set : Accessing, Deletion and Insertion Time is O(logN)

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

### Unordered Set : Average Accessing, Deletion and Insertion Time is O(1)

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

## Stack and Queues in STL

- Stack works on LIFO principle and the most handy functions it provides are as follows:

  - top: to retreive(not remove) the topmost element
  - push: to push elements onto the stack
  - pop: to pop the elements off the stack

- Queue works on FIFO principle and the most common functions are:
  - front : to retrieve(not remove) the first element in the queue
  - push: to push elements in the back of the queue
  - pop: to pop elements from the front of the queue

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
    while (!q.empty())
    {
        cout << q.front() << endl;
        q.pop();
    }


    return 0;
}
```

# Data Structures and Algorithms

## Recursion

- It breaks large problems into smaller ones, and once we devise a solution for the larger one then it eventually adds upto the solution of large problems.

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

- Or when we pass some array/string/variable and we need to come back up in the function to perform some operation on it then we might need to use backtracking if the operations are needed to be performed on the previous version of the variable, i.e., the one with which the recursion was called.

- `It's nothing different from recursion, just a fancy name.`

### Combination Sum : Taking the same element multiple times

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
