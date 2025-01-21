#include <bits/stdc++.h>
using namespace std;
void fn(stack<int> &st, int el)
{
	if (st.empty() || st.top() <= el)
	{
		st.push(el);
		return;
	}

	int top = st.top();
	st.pop();
	fn(st, el); // 4 2 1
	st.push(top);
}

void sort_stack(stack<int> &st)
{
	if (st.size() == 1)
	{
		return;
	}
	int el = st.top();
	st.pop();
	sort_stack(st);
	fn(st, el);
}

void sortStack(stack<int> &stack)
{
	sort_stack(stack);
}