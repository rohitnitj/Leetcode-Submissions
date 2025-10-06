#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));
        
        // min-heap: {elevation, x, y}
        priority_queue<array<int,3>, vector<array<int,3>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});
        vis[0][0] = 1;
        
        int maxTime = 0;
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        
        while (!pq.empty()) {
            auto [elev, x, y] = pq.top();
            pq.pop();
            
            maxTime = max(maxTime, elev);
            
            if (x == n - 1 && y == n - 1)
                return maxTime;
            
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                
                if (nx >= 0 && ny >= 0 && nx < n && ny < n && !vis[nx][ny]) {
                    vis[nx][ny] = 1;
                    pq.push({grid[nx][ny], nx, ny});
                }
            }
        }
        return -1; // should never reach here
    }
};
