#include <bits/stdc++.h>
using namespace std;

// O(N*log(N))
class Solution1 {

private:
    bool check_subfolder(string check, string to_check) {
        int n1 = check.size(), n2 = to_check.size();
        int i = 0;
        for (; i < min(n1, n2); i++) {
            if (check[i] != to_check[i]) return false;
        }

        if (to_check[i] == '/') return true;
        return false;

    }
public:
    vector<string> removeSubfolders(vector<string>& v) {
        sort(v.begin(), v.end());
        vector<string> ans;
        ans.push_back(v[0]);
        string check = v[0];

        for (int i = 1; i < v.size(); i++) {
            if (!check_subfolder(check, v[i])) {
                check = v[i];
                ans.push_back(v[i]);
            }
        }
        return ans;
    }
};


int main() {


    return 0;
}