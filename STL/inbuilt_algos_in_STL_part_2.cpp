#include <bits/stdc++.h>
using namespace std;

bool is_positive(int x) {
    return x > 0;
}

int main() {

    vector<int> v = { 2,4,6,7 };
    //using regular function
    cout << all_of(v.begin(), v.end(), is_positive) << endl;

    //using lambda function
    cout << any_of(v.begin(), v.end(), [](int x) {return x > 0;}) << endl;
    cout << none_of(v.begin(), v.end(), [](int x) {return x > 0;}) << endl;

    // Lambda function
    cout << [](int x, int y) {return x + y;}(2, 3) << endl; // calling the anonymous lambda function
    auto sum = [](int x, int y) {return x + y;};
    cout << sum(2, 5) << endl;
    return 0;
}