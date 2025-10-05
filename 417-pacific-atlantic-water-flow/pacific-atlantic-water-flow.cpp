class Solution {
public:
    int m, n;
    vector<vector<int>> dirs{{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(int r, int c, vector<vector<int>>& heights, vector<vector<bool>>& ocean) {
        ocean[r][c] = true;
        for (auto &d : dirs) {
            int nr = r + d[0], nc = c + d[1];
            if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
            if (ocean[nr][nc]) continue; // already visited
            if (heights[nr][nc] < heights[r][c]) continue; // must be >= current
            dfs(nr, nc, heights, ocean);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        // Pacific (top & left)
        for (int c = 0; c < n; ++c) dfs(0, c, heights, pacific);
        for (int r = 0; r < m; ++r) dfs(r, 0, heights, pacific);

        // Atlantic (bottom & right)
        for (int c = 0; c < n; ++c) dfs(m-1, c, heights, atlantic);
        for (int r = 0; r < m; ++r) dfs(r, n-1, heights, atlantic);

        vector<vector<int>> res;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (pacific[r][c] && atlantic[r][c]) {
                    res.push_back({r, c});
                }
            }
        }
        return res;
    }
};
