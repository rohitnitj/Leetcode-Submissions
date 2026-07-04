class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& road : roads) {
            int u = road[0], v = road[1], d = road[2];
            adj[u].push_back({v, d});
            adj[v].push_back({u, d});
        }
        
        queue<int> q;
        vector<bool> vis(n + 1, false);
        
        q.push(1);
        vis[1] = true;
        
        int ans = INT_MAX;
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            for (auto& [child, dist] : adj[node]) {
                ans = min(ans, dist);
                
                if (!vis[child]) {
                    vis[child] = true;
                    q.push(child);
                }
            }
        }
        
        return ans;
    }
};