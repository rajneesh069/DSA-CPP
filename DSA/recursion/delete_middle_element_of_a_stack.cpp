#include <bits/stdc++.h>
using namespace std;


void delete_middle_element_from_stack(stack<int>& st, int original_size) {
    int curr_size = st.size();

    if (curr_size == 0) {
        return;
    }

    if (curr_size == ceil(original_size / 2)) {
        st.pop();
        return;
    }

    int top = st.top();
    st.pop();
    delete_middle_element_from_stack(st, original_size);
    st.push(top);
}


int main() {
    stack<int> st;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        st.push(x);
    }
    delete_middle_element_from_stack(st, n);

    while (!st.empty()) {
        int top = st.top();
        cout << top << " ";
        st.pop();
    }

    return 0;
}