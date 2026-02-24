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
    int sumRootToLeaf(TreeNode* root) {

        queue<TreeNode*> q; 
        q.push( root ) ;

        int ans = 0 ;

        while( !q.empty() ) {
            int sz = q.size() ;

            for( int i = 0 ; i < sz ; i++ ) {
                TreeNode* node = q.front() ;
                q.pop() ;

                int x = 2 * node -> val ;

                if( node -> left ){ 
                    node -> left -> val += x ;
                    q.push(node -> left ) ;
                }

                if( node -> right ) {
                    node -> right -> val += x ; 
                    q.push( node -> right ) ;
                }

                if( node -> left == NULL && node -> right == NULL ) {
                    ans += node -> val ;
                }
            }
        }     

        return ans ;    
    }
};