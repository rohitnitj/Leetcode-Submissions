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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder ; 
        TreeNode *curr = root ; 

        while( curr != NULL ) {
            preorder.push_back( curr -> val ) ; 

            if( curr -> left == NULL ) {
                curr = curr -> right ; 
            }
            else {
                TreeNode* prev = curr -> left ; 
                while( prev -> right != NULL && prev -> right != curr ) {
                    prev = prev -> right ; 
                }

                if( prev -> right == curr ) {
                    preorder.pop_back() ; 
                    prev -> right = NULL ; 
                    curr = curr -> right ; 
                }
                else {
                    prev -> right = curr ; 
                    curr = curr -> left ; 
                }
            }
        }

        return preorder ; 
    }
};