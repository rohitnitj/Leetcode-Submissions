class Solution {
public:
    struct T {
        int t, x, y;
        T(int a, int b, int c) : t(a), x(b), y(c) {}
        bool operator<(const T &d) const { return t > d.t; } // Min-heap
    };

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size(), ans = 0;
        priority_queue<T> pq;
        pq.push(T(grid[0][0], 0, 0));
        vector<vector<int>> seen(n, vector<int>(n, 0));
        seen[0][0] = 1;
        static int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while (true) {
            auto p = pq.top(); pq.pop();
            ans = max(ans, p.t);
            if (p.x == n - 1 && p.y == n - 1) return ans;

            for (auto &d : dir) {
                int i = p.x + d[0], j = p.y + d[1];
                if (i >= 0 && i < n && j >= 0 && j < n && !seen[i][j]) {
                    seen[i][j] = 1;
                    pq.push(T(grid[i][j], i, j));
                }
            }
        }
    }
};
