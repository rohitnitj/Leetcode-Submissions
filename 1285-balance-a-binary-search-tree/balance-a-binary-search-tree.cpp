class Solution {
public:
    void inorder(TreeNode *root, vector<int> &arr ) {
        if( root == NULL ) return ;

        inorder( root -> left, arr ) ;
        arr.push_back(root -> val ) ;
        inorder( root -> right, arr ) ;
    }

    TreeNode* dfs(vector<int> &arr, int l, int r ) {
        if( l > r ) return NULL ;

        int m = ( l + r ) / 2 ;
        TreeNode* root = new TreeNode( arr[m]) ;

        root -> left = dfs(arr, l, m-1 ) ;
        root -> right = dfs(arr, m+1, r ) ;

        return root ;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr ;
        inorder(root, arr ) ;
        int n = arr.size() ;

        TreeNode *ans = new TreeNode(arr[n/2] ) ;
        return dfs(arr, 0, n-1 ) ;
    }
};