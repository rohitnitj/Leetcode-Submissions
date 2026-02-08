class Solution {
public:

    int maxDepth(TreeNode* root) {
        
        if (root == NULL ) {
            return 0 ;
        }

        int left = maxDepth(root -> left ) ;
        int right = maxDepth(root -> right ) ;

        if( left == -1 || right == -1 ) return -1 ;
        if( abs ( left - right ) > 1 ) return -1 ;

        return  max( left , right ) + 1 ;

    }

    bool isBalanced(TreeNode* root) {
        
        return maxDepth(root) != -1 ;
    }
};
