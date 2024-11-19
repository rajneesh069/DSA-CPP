#include <bits/stdc++.h>
using namespace std;

class SortedStack {
public:
    stack<int> s;
    void sort();
};

void insert_at_correct_position(stack<int>& st, int el) {
    if (st.empty()) {
        st.push(el);
        return;
    }
    if (st.top() <= el) {
        st.push(el);
        return;
    }

    int top = st.top();
    st.pop();
    insert_at_correct_position(st, el);
    st.push(top);
}

void my_sort(stack<int>& st) {
    if (st.empty()) {
        return;
    }

    int top = st.top();
    st.pop();
    my_sort(st);
    insert_at_correct_position(st, top);
}

void SortedStack::sort() {
    my_sort(s);
}

int main() {


    return 0;
}