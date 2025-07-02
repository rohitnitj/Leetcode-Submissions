class Solution {
public:
    void solve(TreeNode* root, int &maxi, int &ans ) {
        if( root -> val >= maxi ) ans++ ;
        maxi = max(maxi, root -> val ) ;

        if( root -> left ) {
            int curr = maxi ;
            solve(root -> left, maxi, ans ) ;
            maxi = curr ;
        }

        if( root -> right ) {
            int curr = maxi ;
            solve(root -> right, maxi, ans ) ;
            maxi = curr ;
        }

        return ;
    }

    int goodNodes(TreeNode* root) {
        int maxi = -1e4-1, ans = 0 ;
        solve(root, maxi, ans ) ;
        return ans ;
    }
};