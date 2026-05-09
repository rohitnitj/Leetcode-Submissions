class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int num_layers = min(m, n) / 2;
        
        for (int i = 0; i < num_layers; ++i) {
            int top = i;
            int bottom = m - 1 - i;
            int left = i;
            int right = n - 1 - i;
            
            vector<int> layer;
            
            for (int j = left; j <= right; ++j) layer.push_back(grid[top][j]);      // Top row
            for (int j = top + 1; j <= bottom; ++j) layer.push_back(grid[j][right]);// Right col
            for (int j = right - 1; j >= left; --j) layer.push_back(grid[bottom][j]);// Bottom row
            for (int j = bottom - 1; j > top; --j) layer.push_back(grid[j][left]);  // Left col
            
            int shifts = k % layer.size();
            rotate(layer.begin(), layer.begin() + shifts, layer.end());
            
            int idx = 0;
            for (int j = left; j <= right; ++j) grid[top][j] = layer[idx++];
            for (int j = top + 1; j <= bottom; ++j) grid[j][right] = layer[idx++];
            for (int j = right - 1; j >= left; --j) grid[bottom][j] = layer[idx++];
            for (int j = bottom - 1; j > top; --j) grid[j][left] = layer[idx++];
        }
        
        return grid;
    }
};