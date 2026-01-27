class Solution {
public:
    long long minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n), radj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            radj[e[1]].push_back({e[0], e[2]});
        }

        const long long INF = 1e18;
        vector<vector<long long>> dist(n, vector<long long>(2, INF));

        priority_queue<
            pair<long long, pair<int,int>>,
            vector<pair<long long, pair<int,int>>>,
            greater<>
        > pq;

        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            auto [d, s] = pq.top(); pq.pop();
            int u = s.first;
            int mode = s.second;

            if (d > dist[u][mode]) continue;

            // normal edges
            for (auto &[v, w] : adj[u]) {
                if (dist[v][0] > d + w) {
                    dist[v][0] = d + w;
                    pq.push({dist[v][0], {v, 0}});
                }
            }

            // reverse incoming edges
            for (auto &[v, w] : radj[u]) {
                if (dist[v][1] > d + 2LL * w) {
                    dist[v][1] = d + 2LL * w;
                    pq.push({dist[v][1], {v, 1}});
                }
            }
        }

        long long ans = min(dist[n-1][0], dist[n-1][1]);
        return ans == INF ? -1 : ans;
    }
};
