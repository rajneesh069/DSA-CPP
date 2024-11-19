#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void insert_at_bottom(stack<int>& st, int el) {
        if (st.empty()) {
            st.push(el);
            return;
        }

        int top = st.top();
        st.pop();
        insert_at_bottom(st, el);
        st.push(top);
    }

    void reverse(stack<int>& st) {
        if (st.empty()) {
            return;
        }

        int top = st.top();
        st.pop();
        reverse(st);
        insert_at_bottom(st, top);
    }
public:
    void Reverse(stack<int>& st) {
        reverse(st);
    }
};

int main() {


    return 0;
}