#include <bits/stdc++.h>
using namespace std;

string LCS(string& a, string& b, int i, int j) {
    if (i == 0 || j == 0) {
        return "";
    }

    if (a[i - 1] == b[j - 1]) {
        string temp = LCS(a, b, i - 1, j - 1);
        temp.push_back(a[i - 1]);
        return temp;

    } else {
        string temp1 = LCS(a, b, i - 1, j);
        string temp2 = LCS(a, b, i, j - 1);

        if (temp1.size() > temp2.size()) return temp1;
        return temp2;
    }

}


int main() {
    string a, b;
    cin >> a >> b;
    string ans = LCS(a, b, a.size(), b.size());
    cout << ans << ", length:" << ans.size() << endl;

    return 0;
}
