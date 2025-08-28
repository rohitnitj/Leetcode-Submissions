class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int, vector<int>> diag;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                diag[i - j].push_back(grid[i][j]);
            }
        }
        
        for (auto& [d, vec] : diag) {
            if (d >= 0) sort(vec.begin(), vec.end(), greater<int>()); 
            else sort(vec.begin(), vec.end()); 
        }
        
        unordered_map<int, int> idx; 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int d = i - j;
                grid[i][j] = diag[d][idx[d]++];
            }
        }
        
        return grid;
    }
};