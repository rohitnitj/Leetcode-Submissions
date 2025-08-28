class Solution {
public:
    void dfs(TreeNode *root, unordered_map<int, int> &mpp, int level ) {
        if( !root ) return ;

        mpp[level] += root -> val ;

        dfs( root -> left, mpp, level + 1 ) ;
        dfs( root -> right, mpp, level + 1 ) ;
    }

    int deepestLeavesSum(TreeNode* root) {
        unordered_map<int, int> mpp ;
        dfs(root, mpp, 1 ) ;

        int maxi = 0, ans = 0 ;
        for( auto &[l, v] : mpp ) {
            if( l > maxi ) {
                maxi = l ;
                ans = v ;
            }
        }

        return ans ;
    }
};