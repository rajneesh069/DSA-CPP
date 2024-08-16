#include <bits/stdc++.h>
using namespace std;

vector<int> NGE(vector<int>& temp) {
    vector<int> nge(temp.size());
    stack<int> st;
    for (int i = 0; i < temp.size(); i++) {
        while (!st.empty() && temp[i] > temp[st.top()]) {
            nge[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty()) {
        nge[st.top()] = -1;
        st.pop();
    }
    return nge;
}

vector<int> nextGreaterElements(vector<int>& nums) {
    vector<int> temp;
    for (auto& el : nums) {
        temp.push_back(el);
    }
    for (auto& el : nums) {
        temp.push_back(el);
    }

    vector<int> nge = NGE(temp);
    vector<int> ans(nge.size() / 2);

    for (int i = 0; i < nge.size() / 2; i++) {
        if (nge[i] > 0) {
            ans[i] = temp[nge[i]];
        }
        else {
            ans[i] = -1;
        }
    }

    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vector<int> ans = nextGreaterElements(nums);
    for (auto&& i : ans)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}