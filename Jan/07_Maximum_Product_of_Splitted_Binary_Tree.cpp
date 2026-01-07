// 1339. Maximum Product of Splitted Binary Tree
// Daily Challenge - 07/01/2026

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    long long totalSum = 0;
    long long bestProduct = 0;
    const int MOD = 1e9 + 7;

    long long dfsTotal(TreeNode* root) {
        if (!root) return 0;
        return root->val + dfsTotal(root->left) + dfsTotal(root->right);
    }

    long long dfs(TreeNode* root) {
        if (!root) return 0;

        long long left = dfs(root->left);
        long long right = dfs(root->right);

        long long currSum = root->val + left + right;

        bestProduct = max(bestProduct, currSum * (totalSum - currSum));

        return currSum;
    }

    int maxProduct(TreeNode* root) {
        totalSum = dfsTotal(root);
        dfs(root);
        return bestProduct % MOD;
    }
};