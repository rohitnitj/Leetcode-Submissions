class Solution {
public:
    int m, n;
    int totalPaths = 0;
    int emptyCount = 0;
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        int startX, startY;
        
        // Count empty squares and find start
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) emptyCount++;
                else if(grid[i][j] == 1) {
                    startX = i;
                    startY = j;
                }
            }
        }
        
        // Start DFS
        dfs(grid, startX, startY, -1);  // start cell counted as visited (-1)
        
        return totalPaths;
    }
    
    void dfs(vector<vector<int>>& grid, int x, int y, int count) {
        // Out of bounds or obstacle
        if(x < 0 || y < 0 || x >= m || y >= n || grid[x][y] == -1) return;
        
        // If reached end
        if(grid[x][y] == 2) {
            if(count == emptyCount) totalPaths++; // Valid path
            return;
        }
        
        // Mark as visited
        int temp = grid[x][y];
        grid[x][y] = -1;
        
        // Move in 4 directions
        dfs(grid, x+1, y, count+1);
        dfs(grid, x-1, y, count+1);
        dfs(grid, x, y+1, count+1);
        dfs(grid, x, y-1, count+1);
        
        // Backtrack
        grid[x][y] = temp;
    }
};
