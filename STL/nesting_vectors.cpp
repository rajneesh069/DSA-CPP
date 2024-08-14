#include <bits/stdc++.h>
using namespace std;

void printVec(vector<pair<int, int>>& v) {
    cout << "size: " << v.size() << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i].first << " " << v[i].second << endl;
    }
}

void printVec(vector<int>& v) {
    cout << "size: " << v.size() << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}


int main() {
    // vector of pairs
    vector<pair<int, int>> v = {
     {1,2}, {2,3}, {3,4}
    };
    printVec(v);

    // array of vectors
    int N; // number of vectors inside the array
    cin >> N;
    vector<int> v1[N];
    for (int i = 0; i < N; i++) {
        int n; // size of each vector
        cin >> n;
        for (int j = 0; j < n; j++) {
            int x; // value inside each vector
            cin >> x;
            v1[i].push_back(x); // pushing x in the ith vector
        }
    }
    for (int i = 0; i < N; i++) {
        printVec(v1[i]);
    }

    vector<vector<int>> v2; // Vector of vectors : v2[i] -> vector
    int K;
    cin >> K;
    // now v2[i] cannot be accessed until there's something inside it.
    // so either create a temp vector and push everything in it and then 
    // push it in the v2 vector or v2.push_back(vector<int> ());
    // Both will work
    for (int i = 0; i < K; i++) {
        int n;
        cin >> n;
        vector<int> temp;
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            temp.push_back(x);
        }
        v2.push_back(temp);
    }

    // print v2
    cout << "v2: " << endl;
    for (int i = 0; i < v2.size(); i++) {
        printVec(v2[i]);
    }
    return 0;
}