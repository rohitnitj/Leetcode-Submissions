class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size() ; 
        int m = grid[0].size() ; 

        queue<pair<int, pair<int, int>>> q ; 
        for( int i = 0 ; i < n; i++ ) {
            for( int j = 0 ; j < m ; j++ ) {
                if( grid[i][j] == 2 ) {
                    q.push ( {0, {i, j } } ) ; 
                }
            }
        }

        int ans = 0 ; 
        vector<int> drow = {-1, 0, 1, 0 } ; 
        vector<int> dcol = {0, -1, 0, 1 } ;

        while( !q.empty() ) {
            auto it = q.front() ; q.pop() ; 
            int curr = it.first ;
            int r = it.second.first ; 
            int c = it.second.second ; 

            ans = max(ans, curr ) ; 
            for( int i = 0 ; i < 4 ; i++ ) {
                int nr = r + drow[i] ;  
                int nc = c + dcol[i] ; 

                if( nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1 ) {
                    grid[nr][nc] = 2 ; 
                    q.push( { curr + 1, { nr, nc } } ) ; 
                }
            }
        }

        for( int i = 0 ; i < n; i++ ) {
            for( int j = 0 ; j < m ; j++ ) {
                if( grid[i][j] == 1 ) return -1 ; 
            }
        }

        return ans ; 
    }
};