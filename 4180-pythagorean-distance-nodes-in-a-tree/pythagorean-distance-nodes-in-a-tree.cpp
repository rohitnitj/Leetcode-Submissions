class Solution {
public:
    void dfs(int node, int parent, int depth, vector<vector<int>> &adj, vector<int> &dist) {
        dist[node] = depth;
        for (int child : adj[node]) {
            if (child == parent) continue;
            dfs(child, node, depth + 1, adj, dist);
        }
    }

    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {

        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> dx(n, 0), dy(n, 0), dz(n, 0);

        dfs(x, -1, 0, adj, dx);
        dfs(y, -1, 0, adj, dy);
        dfs(z, -1, 0, adj, dz);

        int ans = 0;

        for (int u = 0; u < n; u++) {
            long long a = dx[u];
            long long b = dy[u];
            long long c = dz[u];

            if (a > b) swap(a, b);
            if (b > c) swap(b, c);
            if (a > b) swap(a, b);

            if (a * a + b * b == c * c) ans++;
        }

        return ans;
    }
};