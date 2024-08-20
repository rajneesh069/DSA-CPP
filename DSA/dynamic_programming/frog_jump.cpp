#include <bits/stdc++.h>
using namespace std;

int min_energy_recursive(int ind, vector<int>& heights) {
    if (ind == 0) return 0;
    if (ind == 1) return abs(heights[1] - heights[0]);
    int left = min_energy_recursive(ind - 1, heights) + abs(heights[ind] - heights[ind - 1]);
    int right = min_energy_recursive(ind - 2, heights) + abs(heights[ind] - heights[ind - 2]);

    return (left, right);
}


int min_energy_dp(int ind, vector<int>& dp, vector<int>& heights) {
    if (ind == 0) return 0;
    if (ind == 1) return abs(heights[1] - heights[0]);
    if (dp[ind] != -1) return dp[ind];
    int left = min_energy_dp(ind - 1, dp, heights) + abs(heights[ind] - heights[ind - 1]);
    int right = min_energy_dp(ind - 2, dp, heights) + abs(heights[ind] - heights[ind - 2]);

    return dp[ind] = min(left, right);

}

int min_energy_tabulated(int ind, vector<int>& dp, vector<int>& heights) {
    if (ind == 0) return 0;
    if (ind == 1) return abs(heights[1] - heights[0]);
    dp[0] = 0; dp[1] = abs(heights[1] - heights[0]);
    for (int i = 2; i <= ind; i++) {
        dp[i] = min(dp[i - 1] + abs(heights[i] - heights[i - 1]), dp[i - 2] + abs(heights[i] - heights[i - 2]));
    }
    return dp[ind];
}

int min_energy_space_optimized(int ind, vector<int>& heights) {
    if (ind == 0) return 0;
    if (ind == 1) return abs(heights[1] - heights[0]);
    int prev = abs(heights[1] - heights[0]), prev2 = 0;
    for (int i = 2; i <= ind; i++) {
        int curi = min(prev + abs(heights[i] - heights[i - 1]), prev2 + abs(heights[i] - heights[i - 2]));
        prev2 = prev;
        prev = curi;
    }
    return prev;
}

int main() {
   // Express the question in terms of an index
   // Then do everything with the index as per the question
   // Think of the edge cases, like ind == 1, in this case.
   // Then return the minimum of the things you did on the index 
    return 0;
}