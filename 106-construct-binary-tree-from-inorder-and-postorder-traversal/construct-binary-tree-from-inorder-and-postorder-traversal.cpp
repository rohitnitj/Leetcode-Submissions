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
public:
    TreeNode* build( vector<int> &inorder, int inStart, int inEnd, vector<int> &postorder, int postStart, int postEnd, map<int, int> &inMap ) {
        if( inStart > inEnd || postStart > postEnd ) return NULL ; 

        TreeNode *root = new TreeNode( postorder[postEnd] ) ; 
        
        int inroot = inMap[root -> val ] ;
        int numsleft = inroot - inStart ; 

        root -> left = build( inorder, inStart, inroot - 1, postorder, postStart, postStart + numsleft - 1, inMap ) ; 
        root -> right = build( inorder, inroot + 1, inEnd, postorder, postStart + numsleft, postEnd - 1, inMap ) ; 

        return root ; 
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size() ;

        map<int, int> inMap ; 
        for( int i = 0 ; i < n; i++ ) {
            inMap[inorder[i]] = i ; 
        }

        TreeNode *root = build( inorder, 0, n-1, postorder, 0, n-1, inMap ) ; 
        return root ; 
    }
};