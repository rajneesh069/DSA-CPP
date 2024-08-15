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