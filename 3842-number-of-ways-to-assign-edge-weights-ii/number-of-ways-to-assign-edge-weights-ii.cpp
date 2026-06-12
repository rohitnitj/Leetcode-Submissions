class Solution {
public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n + 1);
        
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        int LOG = 18; 
        vector<vector<int>> up(n + 1, vector<int>(LOG, 0));
        vector<int> depth(n + 1, 0);
        
        auto dfs = [&](auto& self, int u, int p, int d) -> void {
            depth[u] = d;
            up[u][0] = p;
            
            for (int j = 1; j < LOG; j++) {
                up[u][j] = up[up[u][j-1]][j-1];
            }
            
            for (int v : adj[u]) {
                if (v != p) {
                    self(self, v, u, d + 1);
                }
            }
        };
        
        dfs(dfs, 1, 1, 0);
        
        auto getLCA = [&](int u, int v) {
            if (depth[u] < depth[v]) swap(u, v);
            int k = depth[u] - depth[v];
            
            for (int j = LOG - 1; j >= 0; j--) {
                if ((k >> j) & 1) {
                    u = up[u][j];
                }
            }
            
            if (u == v) return u;
            
            for (int j = LOG - 1; j >= 0; j--) {
                if (up[u][j] != up[v][j]) {
                    u = up[u][j];
                    v = up[v][j];
                }
            }
            return up[u][0];
        };
        
        int MOD = 1e9 + 7;
        
        vector<int> pow2(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            pow2[i] = (1LL * pow2[i-1] * 2) % MOD;
        }
        
        vector<int> ans;
        ans.reserve(queries.size());
        
        for (const auto& q : queries) {
            int u = q[0], v = q[1];
            int lca = getLCA(u, v);
            int dist = depth[u] + depth[v] - 2 * depth[lca];
            
            if (dist == 0) {
                ans.push_back(0);
            } else {
                ans.push_back(pow2[dist - 1]);
            }
        }
        
        return ans;
    }
};