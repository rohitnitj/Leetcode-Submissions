class Solution{ 
public:
    int maxMoves( vector<vector<int>> &grid ) {
        int n = grid.size() ;
        int m = grid[0].size() ;

        queue<pair<pair<int,int>,int>> q ;
        vector<vector<int>> vis(n, vector<int>(m, 0 ) ) ;
        
        for( int i = 0 ; i < n ; i++ ) {
            vis[i][0] = 1 ;
            q.push( {{i,0}, 0 } ) ;
        }

        int ans = 0 ;
        vector<int> drow = { -1, 0, 1 } ;
        vector<int> dcol = { 1, 1, 1 } ;

        while( !q.empty() ) {
            int size = q.size() ;

            for( int i = 0 ; i < size ; i++ ) {

                int row = q.front().first.first ;
                int col = q.front().first.second ;
                int cnt = q.front().second ;

                ans = max(ans, cnt ) ;
                q.pop() ;

                for( int i = 0 ; i < 3 ; i++ ) {
                    int nrow = row + drow[i] ;
                    int ncol = col + dcol[i] ;

                    if( nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[row][col] < grid[nrow][ncol] ) {
                        vis[nrow][ncol] = 1 ;
                        q.push( { { nrow, ncol }, cnt + 1 } ) ;
                    }
                }
            }
        }

        return ans ;
    }
};