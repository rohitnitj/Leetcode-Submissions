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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {

        set<int> isChild ; 
        map<int, TreeNode* > mpp ; 

        for( auto &it : descriptions ) {
            int nodeVal = it[0];
            int childVal = it[1] ; 
            int isLeft = it[2] ; 

            TreeNode *node, *child ; 

            if( mpp.find(nodeVal) == mpp.end() ) {
                node = new TreeNode(nodeVal ) ; 
                mpp[nodeVal] = node ; 
            }
            else node = mpp[nodeVal] ; 

            if( mpp.find(childVal) == mpp.end() ) {
                child = new TreeNode(childVal ) ; 
                mpp[childVal] = child ; 
            }
            else child = mpp[childVal] ; 

            if( isLeft ) node -> left = child ; 
            else node -> right = child ; 

            isChild.insert( childVal ) ;
        }

        for( auto &[nodeVal, node] : mpp ) {
            if( isChild.find(nodeVal) == isChild.end() ) return node ; 
        }

        return new TreeNode(-1) ; 
    }
};