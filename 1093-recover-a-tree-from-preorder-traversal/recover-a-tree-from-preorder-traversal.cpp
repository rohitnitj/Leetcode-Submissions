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
typedef long long ll ; 

class Solution {
public:
    int getNodeVal(int &idx, string &traversal ) {
        int val = 0 ; 
        while( idx < traversal.size() && traversal[idx] >= '0' && traversal[idx] <= '9' ) {
            val = val * 10 + ( traversal[idx] - '0')  ;
            idx++ ; 
        }
        return val ; 
    }

    int getDepth( int &i, string &traversal ) {
        int depth = 0 ; 
        while( i < traversal.size() && traversal[i] == '-' ) {
            i++ ; 
            depth++ ;
        }
        return depth ; 
    }

    TreeNode* recoverFromPreorder(string traversal) {
        int n = traversal.size() ; 

        int i = 0 ; 
        int nodeVal = getNodeVal(i, traversal) ; 
        TreeNode *root = new TreeNode(nodeVal ) ; 

        stack<TreeNode*> st ; 
        st.push(root) ; 

        while( i < n ) {
            int depth = getDepth(i, traversal ) ; 
            int nodeVal = getNodeVal(i, traversal ) ;         
            
            while( st.size() > depth ) {
                st.pop() ; 
            }

            TreeNode *curr = st.top() ; 

            if( curr -> left == NULL ) {
                curr -> left = new TreeNode( nodeVal ) ; 
                st.push( curr -> left ) ; 
            }
            else if( curr -> right == NULL ) {
                curr -> right = new TreeNode( nodeVal ) ; 
                st.push( curr -> right ) ; 
            }
        }

        return root ; 
    }
};