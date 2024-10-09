#include <bits/stdc++.h>
using namespace std;

vector<long long int> twoOddNum(long long int v[], long long int N) {
    long long int x = 0;
    for (long long int i = 0; i < N; i++) {
        x ^= v[i];
    }
    long long int j = 0;
    while ((x & 1) == 0) {
        x >>= 1;
        j++;
    }

    long long int a = 0, b = 0;
    for (long long int i = 0; i < N; i++) {
        if (((v[i] >> j) & (1)) == 0) {
          //   cout<<v[i]<<endl;
            a ^= v[i];
        } else {
            b ^= v[i];
        }
    }

    vector<long long int>ans;
    if (a < b) {
        ans.push_back(b);
        ans.push_back(a);
        return ans;
    }
    ans.push_back(a);
    ans.push_back(b);
    return ans;

}


int main() {


    return 0;
}