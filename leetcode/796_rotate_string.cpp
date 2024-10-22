#include <bits/stdc++.h>
using namespace std;

bool rotateString(string s, string goal) {
    if (s.size() != goal.size())
        return false;

    int n = s.size();

    for (int i = 0; i < n; i++) {
        goal.push_back(goal[i]);
    }

    int j = 0;
    while (j < goal.size()) {
        int count_iterations = 0;
        for (int i = j; i < j + n; i++) {
            if (goal[i] != s[i - j]) {
                j++;
                break;
            }
            count_iterations++;
        }
        if (count_iterations == n) return true;
    }

    return false;
}

int main() {


    return 0;
}