class Solution {
    int pre = 0, post = 0 ;

public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        TreeNode *curr = new TreeNode(preorder[pre] ) ;
        pre++ ;
        
        if( curr -> val != postorder[post] ) curr -> left = constructFromPrePost(preorder, postorder ) ;
        if( curr -> val != postorder[post] ) curr -> right = constructFromPrePost(preorder, postorder ) ;
        post++ ;

        return curr ;
    }
};