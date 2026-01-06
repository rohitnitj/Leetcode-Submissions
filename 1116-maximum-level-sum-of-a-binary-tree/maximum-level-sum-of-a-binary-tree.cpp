class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int ans = 1, maxi = root ->  val, level = 0 ;
        queue< TreeNode* > q ;
        q.push(root) ;  

        while( !q.empty() ) {
            level++ ;
            int sz = q.size() ;
            int sum = 0 ;

            while( sz-- ) {
                TreeNode *node = q.front() ;
                q.pop() ;
                sum += node -> val ;

                if( node -> left ) q.push( node -> left ) ;
                if( node -> right ) q.push( node -> right ) ;
            }

            if( sum > maxi ) {
                maxi = sum ;
                ans = level ;
            }
        }

        return ans ;
    }
};