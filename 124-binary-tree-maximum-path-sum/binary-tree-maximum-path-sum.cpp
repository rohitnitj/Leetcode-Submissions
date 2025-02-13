class Solution {
private:
    int func(TreeNode* root, int &ans ) {
        if( root == NULL ) return 0 ;

        int lh = max(0, func( root -> left, ans ) ) ;
        int rh = max(0, func( root -> right, ans ) ) ;

        ans = max( ans, root -> val + lh + rh ) ;
        return root -> val + max( lh, rh ) ;
    }

public:
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN ;
        func(root, ans ) ;
        return ans ;
    }
};