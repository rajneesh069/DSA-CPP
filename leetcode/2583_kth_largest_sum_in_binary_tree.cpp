#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left),
        right(right) {
    }
};


// long long kthLargestLevelSum(TreeNode* root, int k) {
//     queue<TreeNode*> q;
//     q.push(root);
//     vector<vector<int>> v;
//     while (!q.empty()) {
//         int level_size = q.size();
//         vector<int> current_level;

//         for (int i = 0; i < level_size; i++) {
//             TreeNode* node = q.front();
//             q.pop();
//             current_level.push_back(node->val);
//             if (node->left) {
//                 q.push(node->left);
//             }

//             if (node->right) {
//                 q.push(node->right);
//             }
//         }

//         v.push_back(current_level);
//     }

//     priority_queue<long long> sum;
//     for (auto& it : v) {
//         long long s = 0;
//         for (auto& el : it) {
//             s += el;
//         }
//         sum.push(s);
//     }

//     if (sum.size() < k) return -1;

//     k--;
//     while (k--) {
//         sum.pop();
//     }

//     return sum.top();
// }

// Space optimized code
long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode *> q;
        q.push(root);
        priority_queue<long long> sum;

        while (!q.empty()) {
            int level_size = q.size();
            long long current_level_sum = 0;

            for (int i = 0; i < level_size; i++) {
                TreeNode* node = q.front();
                q.pop();
                current_level_sum += node->val;
                if (node->left) {
                    q.push(node->left);
                }

                if (node->right) {
                    q.push(node->right);
                }
            }

            sum.push(current_level_sum);
        }

        if(sum.size()<k) return -1;
        
        k--;
        while(k--){
            sum.pop();
        }

        return sum.top();
    }

int main() {


    return 0;
}