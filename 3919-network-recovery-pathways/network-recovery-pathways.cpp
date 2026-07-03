class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int, int>>> adj(n);
        int max_w = 0;
        
        for (const auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            max_w = max(max_w, e[2]);
        }
        
        auto check = [&](int mid) {
            vector<long long> memo(n, -1);
            auto dfs = [&](auto& self, int u) -> long long {
                if (u == n - 1) return 0;
                if (memo[u] != -1) return memo[u];
                
                long long res = 1e18;
                for (auto& edge : adj[u]) {
                    int v = edge.first;
                    int w = edge.second;
                    if (w >= mid && online[v]) {
                        long long nxt = self(self, v);
                        if (nxt != 1e18) {
                            res = min(res, w + nxt);
                        }
                    }
                }
                return memo[u] = res;
            };
            return dfs(dfs, 0) <= k;
        };

        int low = 0, high = max_w, ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return ans;
    }
};