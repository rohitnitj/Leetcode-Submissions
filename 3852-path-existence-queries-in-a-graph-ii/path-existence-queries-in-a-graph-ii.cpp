class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int, int>> sorted_nums(n);
        for (int i = 0; i < n; ++i) {
            sorted_nums[i] = {nums[i], i};
        }
        sort(sorted_nums.begin(), sorted_nums.end());
        
        vector<int> V(n);
        vector<int> orig_to_sorted(n);
        for (int i = 0; i < n; ++i) {
            V[i] = sorted_nums[i].first;
            orig_to_sorted[sorted_nums[i].second] = i; 
        }
        
        int LOG = 18; 
        
        vector<vector<int>> up(LOG, vector<int>(n));
        
        for (int i = 0; i < n; ++i) {
            auto it = upper_bound(V.begin(), V.end(), V[i] + maxDiff);
            up[0][i] = distance(V.begin(), it) - 1;
        }
        
        for (int j = 1; j < LOG; ++j) {
            for (int i = 0; i < n; ++i) {
                up[j][i] = up[j-1][up[j-1][i]];
            }
        }
        
        vector<int> ans;
        ans.reserve(queries.size());
        
        for (const auto& q : queries) {
            int u = q[0], v = q[1];
            
            if (u == v) {
                ans.push_back(0);
                continue;
            }
            
            int A = orig_to_sorted[u];
            int B = orig_to_sorted[v];
            
            if (A > B) {
                swap(A, B);
            }
            
            if (up[LOG-1][A] < B) {
                ans.push_back(-1);
                continue;
            }
            
            int jumps = 0;
            
            for (int j = LOG - 1; j >= 0; --j) {
                if (up[j][A] < B) {
                    A = up[j][A]; 
                    jumps += (1 << j); 
                }
            }
            
            ans.push_back(jumps + 1);
        }
        
        return ans;
    }
};