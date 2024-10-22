#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int remove_whitespaces(string& s) {
        int start = 0;
        while (start < s.size() && s[start] == ' ') {
            start++;
        }
        return start;
    }

    bool isNegative(string& s, int start) {
        return s[start] == '-';
    }

    bool is_digit(char c) {
        return c >= '0' && c <= '9';
    }

public:
    int myAtoi(string& s) {
        int n = s.size();
        int start = remove_whitespaces(s);
        if (start == n) return 0;

        bool is_negative = isNegative(s, start);
        if (s[start] == '-' || s[start] == '+') {
            start++;
        }

        long long ans = 0;
        while (start < n && is_digit(s[start])) {
            int digit = s[start] - '0';

            ans = ans * 10 + digit;

            if (is_negative) {
                if ((-ans) < INT_MIN) {
                    return INT_MIN;
                }
            } else {
                if (ans > INT_MAX) {
                    return INT_MAX;
                }
            }
            start++;
        }

        if (is_negative) ans = -ans;

        if (ans > INT_MAX) return INT_MAX;
        if (ans < INT_MIN) return INT_MIN;

        return ans;
    }
};


int main() {


    return 0;
}