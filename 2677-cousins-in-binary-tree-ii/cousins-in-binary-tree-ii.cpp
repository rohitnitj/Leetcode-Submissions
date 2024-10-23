class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        if( !root ) return root ;

        queue<TreeNode*> q ;
        q.push(root);
        vector<int> levelSums ;

        while( !q.empty() ) {
            int levelSum = 0 ;
            int levelSize = q.size() ;

            for( int i = 0 ; i < levelSize ; i++ ) {
                TreeNode* currNode = q.front() ;
                q.pop() ;

                levelSum += currNode -> val ;
                if( currNode -> left ) q.push(currNode -> left ) ;
                if( currNode -> right ) q.push( currNode -> right ) ;
            }
            levelSums.push_back(levelSum ) ;
        }

        q.push(root) ;
        int levelIndex = 1 ;
        root -> val = 0 ;

        while( !q.empty() ) {
            int levelSize = q.size() ;

            for( int i = 0 ; i < levelSize ; i++ ) {
                TreeNode* currNode = q.front() ;
                q.pop() ;

                int siblingSum = ( currNode -> left ? currNode -> left -> val : 0) + 
                                 ( currNode -> right ? currNode -> right -> val : 0 ) ;

                if( currNode -> left ) {
                    currNode -> left -> val = levelSums[levelIndex] - siblingSum ;
                    q.push( currNode -> left ) ;
                }

                if( currNode -> right ) {
                    currNode -> right -> val = levelSums[levelIndex] - siblingSum ;
                    q.push( currNode -> right ) ;
                }
            }
            levelIndex++ ;
        }

        return root ;
    }
};