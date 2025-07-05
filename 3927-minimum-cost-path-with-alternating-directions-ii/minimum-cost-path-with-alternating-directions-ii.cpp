class Solution {
public:
    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        using ll = long long;
        using T = tuple<ll, int, int, int>; 

        vector<vector<vector<ll>>> dist(m, vector<vector<ll>>(n, vector<ll>(2, 1e18)));
        priority_queue<T, vector<T>, greater<T>> pq;

        dist[0][0][1] = 1;
        pq.push({1, 0, 0, 1});

        vector<int> dx = {0, 1}, dy = {1, 0 } ;

        while (!pq.empty()) {
            auto [c, x, y, p] = pq.top(); pq.pop();
            if (x == m - 1 && y == n - 1) return c;
            if (dist[x][y][p] < c) continue;

            if (p == 1) {
                for (int d = 0; d < 2; d++) {
                    int nx = x + dx[d], ny = y + dy[d];
                    if (nx >= m || ny >= n) continue;
                    ll nc = c + 1LL * (nx + 1) * (ny + 1);
                    if (nc < dist[nx][ny][0]) {
                        dist[nx][ny][0] = nc;
                        pq.push({nc, nx, ny, 0});
                    }
                }
            } else {
                ll nc = c + waitCost[x][y];
                if (nc < dist[x][y][1]) {
                    dist[x][y][1] = nc;
                    pq.push({nc, x, y, 1});
                }
            }
        }

        return -1;
    }
};