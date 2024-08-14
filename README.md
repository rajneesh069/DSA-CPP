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
- Syntax : `container_type :: iterator it`, 'it' is the name of iterator, it could be named anything obviously.
- Iterators point to the elements of a container.
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
