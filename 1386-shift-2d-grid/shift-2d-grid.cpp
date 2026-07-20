class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int total = m * n;
        k = k % total;
        
        if (k == 0) return grid;
        
        vector<vector<int>> result(m, vector<int>(n));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int curr_1d_index = i * n + j;
                int new_1d_index = (curr_1d_index + k) % total;
                result[new_1d_index / n][new_1d_index % n] = grid[i][j];
            }
        }
        
        return result;
    }
};