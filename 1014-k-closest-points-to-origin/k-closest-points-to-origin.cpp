// Upvote and Comment
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Min-heap: stores pairs of (distance, index)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        // Fill the min-heap with all points
        for (int i = 0; i < points.size(); ++i) {
            int x = points[i][0], y = points[i][1];
            int dist = x * x + y * y;
            minHeap.push({dist, i});
        }

        // Collect the k closest points
        vector<vector<int>> result;
        for (int i = 0; i < k; ++i) {
            int idx = minHeap.top().second;
            minHeap.pop();
            result.push_back(points[idx]);
        }

        return result;
    }
};
