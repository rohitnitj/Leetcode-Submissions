class Solution {
public:
    vector<int> dr = {-1, 0, 1, 0 } ; 
    vector<int> dc = {0, -1, 0, 1 } ; 

    void dfs( int r, int c, vector<vector<int>> &grid, int n, int m, int endRow, int endCol, int emptyCount, int &totalPaths ) {
        if( r == endRow && c == endCol ) {
            if( emptyCount == -1 ) totalPaths++ ; 
            return ; 
        }

        int temp = grid[r][c] ; 
        grid[r][c] = -1 ; 

        for( int i = 0 ; i < 4 ; i++ ) {
            int nr = r + dr[i] ; 
            int nc = c + dc[i] ; 

            if( nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] != -1 ) {
                dfs( nr, nc, grid, n, m, endRow, endCol, emptyCount-1, totalPaths ) ; 
            }
        }

        grid[r][c] = temp ; 
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size() ; 

        int emptyCount = 0 ; 
        int startRow, startCol, endRow, endCol ; 

        for( int i = 0 ; i < n; i++ ) {
            for( int j = 0 ; j < m ; j++ ) {
                if( grid[i][j] == 1 ) {
                    startRow = i ; 
                    startCol = j ; 
                }
                else if( grid[i][j] == 2 ) {
                    endRow = i ; 
                    endCol = j ; 
                }
                else if( grid[i][j] == 0 ) {
                    emptyCount++ ; 
                }
            }
        }

        int totalPaths = 0 ;
        dfs(startRow, startCol, grid, n, m, endRow, endCol, emptyCount, totalPaths) ; 
        return totalPaths ; 
    }
};