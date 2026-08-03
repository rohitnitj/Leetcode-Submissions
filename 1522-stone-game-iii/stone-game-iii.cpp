class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> dp(n+1, -1e9 ) ; 
        dp[n] = 0 ; 

        for( int i = n-1; i >= 0 ; i-- ) {
            int currTake = 0; 

            for( int k = 1; k <= 3 && i + k <= n ; k++ ) {
                currTake += stoneValue[i+k-1] ; 
                dp[i] = max( dp[i], currTake - dp[i+k] ) ; 
            }
        }

        return dp[0] > 0 ? "Alice" : dp[0] < 0 ? "Bob" : "Tie" ; 
    }
};