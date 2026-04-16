class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size(); 

        map<int, vector<int>> mpp; 
        for(int i = 0; i < n; i++) {
            mpp[nums[i]].push_back(i); 
        }

        vector<int> ans(n, -1); 
        
        for(auto &[x, v] : mpp) {
            int k = v.size();
            if(k <= 1) continue; 
            
            for(int i = 0; i < k; i++) {
                int curr_idx = v[i];
                
                int prev_idx = v[(i - 1 + k) % k];
                int next_idx = v[(i + 1) % k];
                
                int dist_left = (curr_idx - prev_idx + n) % n;
                int dist_right = (next_idx - curr_idx + n) % n;
                
                ans[curr_idx] = min(dist_left, dist_right);
            }
        }

        vector<int> res; 
        for(int q : queries) {
            res.push_back(ans[q]); 
        }

        return res; 
    }
};