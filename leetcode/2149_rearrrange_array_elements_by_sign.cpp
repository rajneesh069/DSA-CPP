#include <bits/stdc++.h>
using namespace std;

vector<int> rearrangeArray(vector<int>& v) {
    int n = v.size();
    int pos_pos = 0, neg_pos = 1;
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++) {
        if (v[i] > 0) {
            ans[pos_pos] = v[i];
            pos_pos += 2;
        } else {
            ans[neg_pos] = v[i];
            neg_pos += 2;
        }
    }
    return ans;
}

// The unoptimized way is to store all the positive elements in one vector and negative in the other and then push them in the answer or else the above way works fine!

int main() {


    return 0;
}