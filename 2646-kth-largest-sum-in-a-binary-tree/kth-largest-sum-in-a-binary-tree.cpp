class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long > pq ;
        queue<TreeNode*> bfs ;
        bfs.push(root) ;

        while( !bfs.empty() ) {
            long long size = bfs.size() ;
            long long sum = 0 ;

            for( int i = 0 ; i < size ; i++ ) {
                TreeNode* temp = bfs.front() ;
                bfs.pop() ;
                sum += temp -> val ;

                if( temp -> left ) bfs.push(temp -> left ) ;
                if( temp -> right ) bfs.push(temp -> right ) ;
            }

            pq.push(sum) ;
        }

        if( pq.size() < k ) return -1 ;
        for(int i = 0 ; i < k-1 ; i++ ) pq.pop() ;
        return pq.top() ;
    }
};