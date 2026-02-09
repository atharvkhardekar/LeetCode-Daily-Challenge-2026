// 1382. Balance a Binary Search Tree
// Daily Challenge - 09/02/2026

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
    vector<int> inorder;

    void inorderTraversal(TreeNode* root) {
        if (!root) return;
        inorderTraversal(root->left);
        inorder.push_back(root->val);
        inorderTraversal(root->right);
    }

    TreeNode* buildBST(int left, int right) {
        if (left > right) return nullptr;

        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(inorder[mid]);

        root->left = buildBST(left, mid - 1);
        root->right = buildBST(mid + 1, right);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        inorderTraversal(root);
        return buildBST(0, inorder.size() - 1);
    }
};