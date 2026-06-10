class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        int log = 16; 
        
        // Sparse tables for O(1) Range Maximum and Minimum Queries
        vector<array<int, 16>> max_st(n);
        vector<array<int, 16>> min_st(n);
        vector<int> lg(n + 1, 0);

        // Precompute logarithms for O(1) queries
        for (int i = 2; i <= n; i++) {
            lg[i] = lg[i / 2] + 1;
        }

        // Initialize base cases (intervals of length 1)
        for (int i = 0; i < n; i++) {
            max_st[i][0] = nums[i];
            min_st[i][0] = nums[i];
        }

        // Build the sparse tables
        for (int j = 1; j < log; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                max_st[i][j] = max(max_st[i][j - 1], max_st[i + (1 << (j - 1))][j - 1]);
                min_st[i][j] = min(min_st[i][j - 1], min_st[i + (1 << (j - 1))][j - 1]);
            }
        }

        // Lambda helper to get the difference in O(1)
        auto get_val = [&](int l, int r) {
            int j = lg[r - l + 1];
            int mx = max(max_st[l][j], max_st[r - (1 << j) + 1][j]);
            int mn = min(min_st[l][j], min_st[r - (1 << j) + 1][j]);
            return mx - mn;
        };

        // Max-heap stores pairs of: { subarray_value, {l_index, r_index} }
        priority_queue<pair<int, pair<int, int>>> pq;
        
        // Step 1: Push the largest possible subarray starting at each index l
        for (int i = 0; i < n; i++) {
            pq.push({get_val(i, n - 1), {i, n - 1}});
        }

        long long ans = 0;
        
        // Step 2: Extract the maximum k times
        while (k-- > 0 && !pq.empty()) {
            auto [val, range] = pq.top();
            pq.pop();
            
            ans += val;
            
            int l = range.first;
            int r = range.second;
            
            // If we can still shrink the window from the right, push the next best option
            if (r > l) {
                pq.push({get_val(l, r - 1), {l, r - 1}});
            }
        }

        return ans;
    }
};