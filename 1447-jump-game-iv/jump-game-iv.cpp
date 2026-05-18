class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        
        if (n <= 1) return 0;

        unordered_map<int, vector<int>> graph;
        for (int i = 0; i < n; ++i) {
            graph[arr[i]].push_back(i);
        }

        queue<int> q;
        q.push(0);
        
        vector<bool> visited(n, false);
        visited[0] = true;

        int steps = 0;

        while (!q.empty()) {
            int size = q.size();
            
            for (int i = 0; i < size; ++i) {
                int curr = q.front();
                q.pop();

                if (curr == n - 1) {
                    return steps;
                }

                if (curr + 1 < n && !visited[curr + 1]) {
                    visited[curr + 1] = true;
                    q.push(curr + 1);
                }

                if (curr - 1 >= 0 && !visited[curr - 1]) {
                    visited[curr - 1] = true;
                    q.push(curr - 1);
                }

                for (int nextIndex : graph[arr[curr]]) {
                    if (!visited[nextIndex]) {
                        visited[nextIndex] = true;
                        q.push(nextIndex);
                    }
                }
                
                graph[arr[curr]].clear();
            }
            steps++;
        }

        return 0;
    }
};