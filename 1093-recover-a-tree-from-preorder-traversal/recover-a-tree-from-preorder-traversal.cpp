class Solution {
public:
    int getVal(string &traversal, const int &n, int &pos ) {
        int val = 0 ;
        while( pos < n && traversal[pos] >= '0' && traversal[pos] <= '9' ) {
            val = val * 10 + ( traversal[pos] - '0' ) ;
            pos++ ;
        }
        return val ;
    }

    int getDashLen(string &traversal, const int &n, int &pos ) {
        int dash_len = 0 ;
        while( pos < n && traversal[pos] == '-') {
            dash_len++ ;
            pos++ ;
        }
        return dash_len ;
    }
    
    void buildTree(TreeNode *curr, int expected_dash_len, string &traversal, const int &n , int &pos ) {
        if( pos == n ) return ;

        int prev_pos = pos ;
        int dash_len = getDashLen(traversal, n, pos ) ;

        if( dash_len < expected_dash_len ) {
            pos = prev_pos ;
            return ;
        } 

        int node_val = getVal(traversal, n, pos ) ;
        TreeNode* new_node = new TreeNode(node_val ) ;

        if( !curr -> left ) curr -> left = new_node ;
        else                curr -> right = new_node ;

        buildTree(new_node, 1+expected_dash_len, traversal, n, pos ) ;
        buildTree(new_node, 1+expected_dash_len, traversal, n, pos ) ;
    }

    TreeNode* recoverFromPreorder(string traversal) {
        int n = traversal.size() ;
        int pos = 0 ;
        TreeNode *root = new TreeNode(getVal(traversal, n, pos ) ) ;

        buildTree(root, 1, traversal, n, pos ) ;
        buildTree(root, 1, traversal, n, pos ) ;

        return root ;
    }
};