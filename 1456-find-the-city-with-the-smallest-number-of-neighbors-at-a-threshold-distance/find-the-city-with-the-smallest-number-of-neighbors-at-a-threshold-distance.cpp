#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int, int>>> adjList(n);
        for (int i = 0; i < edges.size(); ++i) {
            adjList[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adjList[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        
        int ans = -1;
        int lowestCount = n + 1;
        
        for (int startNode = 0; startNode < n; ++startNode) {
            vector<int> shortestPath(n, 1000000000);
            vector<bool> inQ(n, false);
            queue<int> pendingNodes;
            
            shortestPath[startNode] = 0;
            pendingNodes.push(startNode);
            inQ[startNode] = true;
            
            while (!pendingNodes.empty()) {
                int current = pendingNodes.front();
                pendingNodes.pop();
                inQ[current] = false;
                
                for (int j = 0; j < adjList[current].size(); ++j) {
                    int neighbor = adjList[current][j].first;
                    int weight = adjList[current][j].second;
                    
                    if (shortestPath[current] + weight < shortestPath[neighbor]) {
                        shortestPath[neighbor] = shortestPath[current] + weight;
                        if (!inQ[neighbor]) {
                            pendingNodes.push(neighbor);
                            inQ[neighbor] = true;
                        }
                    }
                }
            }
            
            int reachCount = 0;
            for (int endNode = 0; endNode < n; ++endNode) {
                if (startNode != endNode && shortestPath[endNode] <= distanceThreshold) {
                    reachCount++;
                }
            }
            
            if (reachCount <= lowestCount) {
                lowestCount = reachCount;
                ans = startNode;
            }
        }
        return ans;
    }
};