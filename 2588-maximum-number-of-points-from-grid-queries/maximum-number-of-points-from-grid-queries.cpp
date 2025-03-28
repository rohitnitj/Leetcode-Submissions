class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int n = grid.size();
        int m = grid[0].size();
        int k = queries.size();

        vector<int> ans(k, 0);
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({grid[0][0], {0, 0}});
        visited[0][0] = true;

        vector<int> drow = {-1, 0, 1, 0};
        vector<int> dcol = {0, 1, 0, -1};

        int count = 0;
        vector<pair<int, int>> query_with_index;
        for (int i = 0; i < k; i++) {
            query_with_index.emplace_back(queries[i], i);
        }
        sort(query_with_index.begin(), query_with_index.end());

        int index = 0;

        while (!pq.empty() && index < k) {
            int val = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();

            while (index < k && query_with_index[index].first <= val) {
                ans[query_with_index[index].second] = count;
                index++;
            }

            count++;
            for (int i = 0; i < 4; i++) {
                int nr = r + drow[i];
                int nc = c + dcol[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m && !visited[nr][nc]) {
                    pq.push({grid[nr][nc], {nr, nc}});
                    visited[nr][nc] = true;
                }
            }
        }

        while (index < k) {
            ans[query_with_index[index].second] = count;
            index++;
        }

        return ans;
    }
};