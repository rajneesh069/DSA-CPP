#include <bits/stdc++.h>
using namespace std;


class Solution {
private:
    void fn(int n, int i, string& ds, vector<string>& ans) {
        if (i == n) {
            ans.push_back(ds);
            return;
        }


        if (i > 0 && ds[i - 1] == '0') {
            ds.push_back('0');
            fn(n, i + 1, ds, ans);
            ds.pop_back();

            ds.push_back('1');
            fn(n, i + 1, ds, ans);
            ds.pop_back();

        } else if (i > 0 && ds[i - 1] == '1') {
            ds.push_back('0');
            fn(n, i + 1, ds, ans);
            ds.pop_back();
        }
    }
public:
    vector<string> generateBinaryStrings(int num) {
        vector<string> ans;
        string ds;

        ds.push_back('0');
        fn(num, 1, ds, ans);
        ds.pop_back();

        ds.push_back('1');
        fn(num, 1, ds, ans);
        ds.pop_back();



        return ans;
    }
};

int main() {


    return 0;
}