class Solution {
public:
    bool isMagicSquare(vector<vector<int>>& grid, int row, int col) {
        vector<int> nums(10, 0);
        
        for (int i = row; i < row + 3; i++) {
            for (int j = col; j < col + 3; j++) {
                int num = grid[i][j];
                if (num < 1 || num > 9 || nums[num] == 1) return false;
                nums[num] = 1;
            }
        }
        
        int sum = grid[row][col] + grid[row][col+1] + grid[row][col+2];
        if (grid[row+1][col] + grid[row+1][col+1] + grid[row+1][col+2] != sum) return false;
        if (grid[row+2][col] + grid[row+2][col+1] + grid[row+2][col+2] != sum) return false;
        if (grid[row][col] + grid[row+1][col] + grid[row+2][col] != sum) return false;
        if (grid[row][col+1] + grid[row+1][col+1] + grid[row+2][col+1] != sum) return false;
        if (grid[row][col+2] + grid[row+1][col+2] + grid[row+2][col+2] != sum) return false;
        if (grid[row][col] + grid[row+1][col+1] + grid[row+2][col+2] != sum) return false;
        if (grid[row][col+2] + grid[row+1][col+1] + grid[row+2][col] != sum) return false;
        
        return true;
    }
    
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        int count = 0;
        
        for (int i = 0; i < row - 2; i++) {
            for (int j = 0; j < col - 2; j++) {
                if (isMagicSquare(grid, i, j)) {
                    count++;
                }
            }
        }
        
        return count;
    }
};
