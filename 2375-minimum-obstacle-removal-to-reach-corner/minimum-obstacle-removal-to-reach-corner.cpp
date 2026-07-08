class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dist(m, vector<int>(n, 1e9));
        deque<pair<int, int>> dq;
        
        dist[0][0] = 0;
        dq.push_front({0, 0});
        
        vector<int> dir = {-1, 0, 1, 0, -1};
        
        while (!dq.empty()) {
            auto [r, c] = dq.front();
            dq.pop_front();
            
            if (r == m - 1 && c == n - 1) {
                return dist[r][c];
            }
            
            for (int i = 0; i < 4; ++i) {
                int nr = r + dir[i];
                int nc = c + dir[i+1];
                
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int newDist = dist[r][c] + grid[nr][nc];
                    
                    if (newDist < dist[nr][nc]) {
                        dist[nr][nc] = newDist;
                        
                        if (grid[nr][nc] == 0) {
                            dq.push_front({nr, nc}); 
                        } 
                        else {
                            dq.push_back({nr, nc});  
                        }
                    }
                }
            }
        }
        
        return dist[m-1][n-1];
    }
};