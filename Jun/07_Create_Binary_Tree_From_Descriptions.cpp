// 2196. Create Binary Tree From Descriptions
// Daily Challenge - 07/06/2026

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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        unordered_set<int> children;

        for (auto &d : descriptions) {
            int parent = d[0];
            int child = d[1];
            int isLeft = d[2];

            if (!mp.count(parent))
                mp[parent] = new TreeNode(parent);

            if (!mp.count(child))
                mp[child] = new TreeNode(child);

            if (isLeft)
                mp[parent]->left = mp[child];
            else
                mp[parent]->right = mp[child];

            children.insert(child);
        }

        for (auto &d : descriptions) {
            int parent = d[0];

            if (!children.count(parent))
                return mp[parent];
        }

        return nullptr;
    }
};