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
    int depth(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(depth(root->left), depth(root->right));
    }

    TreeNode* findLCA(TreeNode* root, int d, int level = 1) {
        if (!root) return nullptr;
        if (level == d) return root;
        
        TreeNode* left = findLCA(root->left, d, level + 1);
        TreeNode* right = findLCA(root->right, d, level + 1);
        
        if (left && right) return root; // LCA found
        return left ? left : right;
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int d = depth(root);  // Find max depth
        return findLCA(root, d);
    }
};
