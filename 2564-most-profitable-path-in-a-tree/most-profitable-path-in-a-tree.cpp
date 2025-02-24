class Solution {
public:
    bool bobPath(int node, vector<vector<int>> &adj, int parent, vector<int> &currPath, vector<int> &finalPath) {
        currPath.push_back(node);
        if (node == 0) {
            finalPath = currPath;
            return true;
        }

        for (auto adj_node : adj[node]) {
            if (adj_node != parent) {
                if (bobPath(adj_node, adj, node, currPath, finalPath)) {
                    return true;
                }
            }
        }

        currPath.pop_back();  // Backtrack
        return false;
    }

    int alicePath(int node, vector<vector<int>> &adj, int parent, vector<int> &amount) {
        int ans = INT_MIN;
        bool isLeaf = true;

        for (auto adj_node : adj[node]) {
            if (adj_node != parent) {
                isLeaf = false;
                ans = max(ans, alicePath(adj_node, adj, node, amount));
            }
        }

        return (isLeaf ? 0 : ans) + amount[node];
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<vector<int>> adj(n);

        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> temp, bob_path;
        bobPath(bob, adj, -1, temp, bob_path);

        int b = bob_path.size();
        for (int i = 0; i < b / 2; i++) amount[bob_path[i]] = 0;
        if (b % 2 == 1) amount[bob_path[b / 2]] /= 2;

        return alicePath(0, adj, -1, amount);
    }
};
