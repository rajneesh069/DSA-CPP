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