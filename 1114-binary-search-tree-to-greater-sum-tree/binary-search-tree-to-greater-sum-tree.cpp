class Solution {
public:
    void postorder( TreeNode* root, int &sum ) {
        if( root == NULL ) return ;

        postorder( root -> right, sum ) ;

        sum += root -> val ;
        root -> val = sum ;

        postorder( root -> left, sum ) ;
    }

    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0 ;
        postorder( root, sum ) ;
        return root ;
    }
};