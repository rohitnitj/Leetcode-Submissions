class Solution {
public:
    bool canReach(std::string s, int minJump, int maxJump) {
        int n = s.length();
        
        if (s[n - 1] != '0') {
            return false;
        }

        std::vector<bool> dp(n, false);
        dp[0] = true; 
        
        int active_count = 0; 

        for (int i = 1; i < n; ++i) {
            if (i >= minJump) {
                active_count += dp[i - minJump] ? 1 : 0;
            }
            if (i > maxJump) {
                active_count -= dp[i - maxJump - 1] ? 1 : 0;
            }

            if (s[i] == '0' && active_count > 0) {
                dp[i] = true;
            }
        }

        return dp[n - 1];
    }
};