class Solution {
    int maxSum = 0;

    // Returns: {isBST, minNode, maxNode, sumIfBST}
    tuple<bool, int, int, int> helper(TreeNode* root) {
        if (!root)
            return {true, INT_MAX, INT_MIN, 0};

        auto [isLeftBST, leftMin, leftMax, leftSum] = helper(root->left);
        auto [isRightBST, rightMin, rightMax, rightSum] = helper(root->right);

        if (isLeftBST && isRightBST && leftMax < root->val && root->val < rightMin) {
            int sum = leftSum + rightSum + root->val;
            maxSum = max(maxSum, sum);
            return {true, min(root->val, leftMin), max(root->val, rightMax), sum};
        }

        return {false, 0, 0, 0};
    }

public:
    int maxSumBST(TreeNode* root) {
        helper(root);
        return maxSum;
    }
};