class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> pos(n + 1);
        
        for (int i = 0; i < n; ++i) {
            pos[nums[i]].push_back(i);
        }
        
        int min_dist = INT_MAX;
        
        for (int i = 1; i <= n; ++i) {
            if (pos[i].size() >= 3) {
                for (size_t j = 2; j < pos[i].size(); ++j) {
                    int dist = 2 * (pos[i][j] - pos[i][j - 2]);
                    min_dist = min(min_dist, dist);
                }
            }
        }
        
        return min_dist == INT_MAX ? -1 : min_dist;
    }
};