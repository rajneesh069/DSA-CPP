#include <bits/stdc++.h>
using namespace std;

void f(int ind, int n, vector<int>& v, int freq[], vector<int>& ds) {
    if (ds.size() == n) { // we will go till we have all the three elements
        for (auto& i : ds) {
            cout << i << " ";
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < n; i++) { // for each element I have to check from i=0 only
    // like in case of [1,2,3] if we take 2 first then [2, 1, 3] is also possible, hence we need i=0.
        if (!freq[i]) {
            freq[i] = 1;
            ds.push_back(v[i]);
            f(i + 1, n, v, freq, ds);
            ds.pop_back();
            freq[i] = 0;
        }
    }


}

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    vector<int> current;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int freq[n] = { 0 };
    f(0, n, v, freq, current);

    return 0;
}
