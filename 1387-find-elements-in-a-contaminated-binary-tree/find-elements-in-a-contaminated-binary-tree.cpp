class FindElements {
    TreeNode* newRoot ;

public:
    FindElements(TreeNode* root) {
        newRoot = root ;
        root -> val = 0 ;

        queue<TreeNode*> q ;
        q.push(root ) ;

        while( !q.empty()) {
            TreeNode *root = q.front() ;
            int x = root -> val ;

            if( root -> left ) {
                root -> left -> val = 2*x + 1 ;
                q.push(root -> left ) ;
            }

            if( root -> right ) {
                root -> right -> val = 2*x + 2 ;
                q.push( root -> right ) ;
            }

            q.pop() ;
        }
    }

    void preOrder(TreeNode* root, int target, bool &flag ) {
        if( !root ) return  ;

        if( root -> val == target ){
            flag = true ;
            return ;
        } 

        preOrder( root -> left, target, flag ) ;
        preOrder( root -> right, target, flag ) ;
    }
    
    bool find(int target) {
        bool flag = false ;
        preOrder(newRoot, target, flag ) ;
        return flag ;
    }
};