class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size() ;
        vector<vector<int>> adj(n) ;
        
        for( int i = 0 ; i < n ; i++ ) {
            for( int j = 0 ; j < rooms[i].size() ; j++ ) {
                adj[i].push_back(rooms[i][j] ) ;
            }
        }

        vector<bool> vis(n, false ) ;
        vis[0] = true ;
        
        queue<int> q ;
        q.push(0) ;

        while( !q.empty() ) {
            int sz = q.size() ;

            while( sz-- ) {
                int idx = q.front() ; 
                q.pop() ;

                vis[idx] = true ;
                for( int i : adj[idx] ) {
                    if ( !vis[i] ) q.push(i) ;
                }
            }
        }

        for( bool v : vis ) if( v == false ) return false ;
        return true ;
    }
};