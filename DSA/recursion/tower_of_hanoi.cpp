#include <bits/stdc++.h>
using namespace std;

void print_steps(char& source, char& helper, char& destination, int n) {

    if (n == 1) {
        cout << "Moving plate " << n << " from " << source << " to " << destination << "\n";
        return;
    }

    print_steps(source, destination, helper, n - 1);
    cout << "Moving plate " << n << " from " << source << " to " << destination << "\n";
    print_steps(helper, source, destination, n - 1);
}


int main() {
    int num_of_plates;
    cin >> num_of_plates;

    char source = 'A', helper = 'B', destination = 'C';
    print_steps(source, helper, destination, num_of_plates);
    return 0;
}