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
    void traverseLeftToRight(TreeNode* root, int currHeight ) {
        if( root == NULL ) return ;

        maxHeightAfterRemoval[root -> val] = currMaxHeight ;
        currMaxHeight = max( currHeight, currMaxHeight ) ;

        traverseLeftToRight(root -> left, currHeight + 1 ) ;
        traverseLeftToRight(root -> right, currHeight + 1 ) ;
    }

    void traverseRightToLeft(TreeNode* root, int currHeight ) {
        if( root == NULL ) return ;

        maxHeightAfterRemoval[root -> val ] = max( maxHeightAfterRemoval[root-> val], currMaxHeight ) ;
        currMaxHeight = max( currHeight, currMaxHeight  ) ;

        traverseRightToLeft( root -> right, currHeight + 1 ) ;
        traverseRightToLeft( root -> left , currHeight + 1 ) ;
    }

public:
    int maxHeightAfterRemoval[100001] = {0} ;
    int currMaxHeight = 0 ;

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {

        traverseLeftToRight( root, 0 ) ;
        currMaxHeight = 0 ;
        traverseRightToLeft( root, 0 ) ;

        vector<int> ans ;
        for( int q : queries ) {
            ans.push_back( maxHeightAfterRemoval[q] ) ;
        }

        return ans ;
    }
};