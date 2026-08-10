class Solution {
public:
    int maxArea(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        
        vector<vector<int>> pref(m + 1, vector<int>(n + 1, 0));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                pref[i + 1][j + 1] = grid[i][j] + pref[i][j + 1] + pref[i + 1][j] - pref[i][j];
            }
        }
        
        int low = 1, high = min(m, n);
        int max_k = 0;
        
        while (low <= high) {
            int k = low + (high - low) / 2;
            
            if (hasTwoNonOverlapping(k, pref, m, n)) {
                max_k = k;     
                low = k + 1;   
            } 
            else {
                high = k - 1;  
            }
        }
        
        return max_k * max_k; 
    }
    
private:
    bool hasTwoNonOverlapping(int k, const vector<vector<int>>& pref, int m, int n) {
        int min_r = INT_MAX, max_r = -1;
        int min_c = INT_MAX, max_c = -1;
        
        for (int r = k; r <= m; ++r) {
            for (int c = k; c <= n; ++c) {
                
                int sum = pref[r][c] - pref[r - k][c] - pref[r][c - k] + pref[r - k][c - k];
                
                if (sum == k * k) {
                    min_r = min(min_r, r - k);
                    max_r = max(max_r, r - k);
                    min_c = min(min_c, c - k);
                    max_c = max(max_c, c - k);
                }
            }
        }
        
        if (max_r == -1) return false;
        return (max_r - min_r >= k) || (max_c - min_c >= k);
    }
};