/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void inorder(TreeNode* root, vector<int> &ans ) {
        if( root == nullptr ) return ;

        inorder( root -> left , ans ) ;
        ans.push_back(root -> val ) ;
        inorder( root -> right, ans ) ;
    }
    
public:
    int minDiffInBST(TreeNode* root) {
        vector<int> arr ;
        inorder(root, arr ) ;

        int ans = 1e9 ;
        int diff ;

        int n = arr.size() ;
        for( int i = 0 ; i < n; i++ ) {
            for( int j = i+1 ; j < n ; j++) {
                diff = abs(arr[i] - arr[j] ) ;
                ans = min( ans, diff ) ;
            }
        }

        return ans ;
    }
};