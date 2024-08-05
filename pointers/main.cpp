#include <bits/stdc++.h>
using namespace std;

void increment(int* x) {
    *x++;
}

int main() {
    int x = 4;
    increment(&x); // or increment(p_x);
    int* p_x = &x;
    // both of them print the same thing, i.e., the address of x, & = address of operator
    cout << "Addr x: " << &x << endl;
    cout << "Val p_x: " << p_x << endl;

    *p_x = 5;
    // both print 5
    cout << "Val x: " << x << endl;
    cout << "Val at *p_x: " << *p_x << endl;

    // pointer arithmetic
    // p_x++;
    // adds 4 bytes(in our case) to the address
    // cout << "Addr x+4: " << p_x << endl;

    // double pointers
    int** p_p_x = &p_x;
    cout << "Addr p_x: " << &p_x << endl;
    cout << "Val p_p_x: " << p_p_x << endl;
    cout << "Val at *p_p_x: " << *p_p_x << endl;
    cout << "Val at **p_p_x: " << **p_p_x << endl;

    // changes the value of x through the double pointer
    **p_p_x = 10;
    cout << "Val x: " << x << endl;

    int a[10];
    a[0] = 2;
    a[1] = 4;
    // both print the same thing
    cout << "a: " << a << endl;
    cout << "&a[0]: " << &a[0] << endl;

    // Accessing the value using the value at(*) operator
    cout << "*a: " << *a << endl;
    cout << "*a+1: " << *(a + 1) << endl; // prints value at index = 1

    return 0;
}