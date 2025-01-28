class Solution {
private:
    void bfs(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &vis, int &ans ){
        int n = grid.size() ;
        int m = grid[0].size() ;

        queue<pair<int,int>> q ;
        q.push({i,j } ) ;

        vector<int> dr = { -1, 0, 1, 0 } ;
        vector<int> dc = { 0, -1, 0, 1 } ;

        int temp = 0 ;

        while( !q.empty() ) {
            auto it = q.front() ;
            q.pop() ;

            int r = it.first ;
            int c = it.second ;
            int val = grid[r][c] ;
            temp += val ;

            for(int d = 0 ; d < 4 ; d++ ) {
                int nr = r + dr[d] ;
                int nc = c + dc[d] ;

                if( nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] != 0 && !vis[nr][nc]) {
                    q.push({nr,nc } ) ;
                    vis[nr][nc] = 1 ;
                }
            }

            ans = max(ans, temp) ;
        }       
    }

public:
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size() ;
        vector<vector<int>> vis(n, vector<int> (m, 0 ) ) ;
        int ans = 0 ;

        for(int i = 0 ; i < n ; i++ ) {
            for( int j = 0 ; j < m ; j++ ) {
                if( !vis[i][j] && grid[i][j] != 0 ) {
                    vis[i][j] = 1 ;
                    bfs(grid, i, j, vis, ans ) ;
                }
            }
        }

        return ans ;
    }
};