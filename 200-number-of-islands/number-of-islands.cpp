class Solution {
private:
    void dfs(vector<vector<char>> &grid, vector<vector<int>> &vis, int x, int y, int n, int m ) {
        vis[x][y] = 1 ;
        vector<int> dx = {-1, 0, 1, 0 } ;
        vector<int> dy = {0, -1, 0, 1 } ;

        for(int i = 0 ; i < 4 ; i++ ) {
            int nx = x + dx[i] ;
            int ny = y + dy[i] ;

            if( nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == '1' &&  !vis[nx][ny]) {
                dfs(grid, vis, nx, ny, n, m ) ;
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size() ; 
        int m = grid[0].size() ;
        vector<vector<int>> vis(n, vector<int> (m, 0 )) ;

        int cnt = 0 ;
        for(int i = 0 ; i < n ; i++ ) {
            for(int j = 0 ; j < m ; j++ ) {

                if( grid[i][j] == '1' && !vis[i][j]) {
                    cnt++ ;
                    dfs(grid, vis, i, j, n, m ) ;
                }
            }
        }

        return cnt ;
    }
};