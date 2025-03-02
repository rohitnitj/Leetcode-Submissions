class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1);
        
        for (int start = 0; start < V; ++start) {
            if (color[start] == -1) {
                queue<int> q;
                q.push(start);
                color[start] = 0;
                
                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    
                    for (int neighbor : graph[node]) {
                        if (color[neighbor] == -1) {
                            color[neighbor] = !color[node];
                            q.push(neighbor);
                        } 
                        else if (color[neighbor] == color[node]) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};