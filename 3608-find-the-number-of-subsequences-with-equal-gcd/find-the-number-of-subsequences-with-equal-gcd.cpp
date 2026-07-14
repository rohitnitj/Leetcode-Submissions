class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        int MOD = 1e9 + 7;
        
        int max_val = 0;
        for (int x : nums) {
            max_val = max(max_val, x);
        }
        
        vector<vector<int>> dp(max_val + 1, vector<int>(max_val + 1, 0));
        dp[0][0] = 1; 
        
        for (int x : nums) {
            vector<vector<int>> next_dp = dp; 
            
            for (int g1 = 0; g1 <= max_val; ++g1) {
                for (int g2 = 0; g2 <= max_val; ++g2) {
                    if (dp[g1][g2] == 0) continue;
                    
                    int count = dp[g1][g2];
                    
                    int next_g1 = (g1 == 0) ? x : std::gcd(g1, x);
                    next_dp[next_g1][g2] = (next_dp[next_g1][g2] + count) % MOD;
                    
                    int next_g2 = (g2 == 0) ? x : std::gcd(g2, x);
                    next_dp[g1][next_g2] = (next_dp[g1][next_g2] + count) % MOD;
                }
            }
            dp = next_dp;
        }
        
        int ans = 0;
        for (int g = 1; g <= max_val; ++g) {
            ans = (ans + dp[g][g]) % MOD;
        }
        
        return ans;
    }
};