class Solution {
private:
    vector<vector<int>> bfs_traversal(TreeNode* root ){
        vector<vector<int>> bfs ;
        queue<TreeNode*> q ;
        q.push( root ) ;

        while( !q.empty() ) {
            int sz = q.size() ;
            vector<int> temp ;

            for( int i = 0 ; i < sz ; i++ ) {
                TreeNode* node = q.front() ;
                q.pop() ;
                temp.push_back(node -> val ) ;
                if( node -> left ) q.push(node -> left ) ;
                if( node  -> right ) q.push ( node -> right ) ;    
            }  

            bfs.push_back(temp ) ;
        }

        return bfs ;
    }

    int find_swap(vector<int> &arr ) {
        int n = arr.size() ;
        vector<int> temp = arr ;
        unordered_map<int, int >  mpp ;

        sort(temp.begin(), temp.end() ) ;

        for( int i = 0 ; i < temp.size() ; i++ ) 
            mpp[temp[i]] = i ;

        vector<int> vis(n, 0 );
        int cnt = 0 ;

        for( int i = 0 ; i < n ; i++ ) {
            if( vis[i] || mpp[arr[i]] == i ) continue; 

            int cycle_size = 0 ;
            int j = i ;

            while( !vis[j] ) {
                vis[j] = 1 ;
                j = mpp[arr[j]] ;
                cycle_size++ ;
            }

            if( cycle_size > 1  ) cnt += (cycle_size - 1 ) ;
        }

        return cnt ;
        
    }
    
public:
    int minimumOperations(TreeNode* root) {
        vector<vector<int>> bfs = bfs_traversal(root ) ;

        int ans = 0 ;
        for( auto arr : bfs ) {
            int cnt = find_swap(arr ) ;
            ans += cnt ;
        }

        return ans ;
    }
};