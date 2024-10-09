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