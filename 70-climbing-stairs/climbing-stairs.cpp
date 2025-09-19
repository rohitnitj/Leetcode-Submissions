class Solution {
public:
    int climbStairs(int n) {
        // base case
        if( n <= 2 ) return n ; 
        
        // dp[i] = number of distinct ways to climb to dp[i] ;
        vector<int> dp(n+1, 0 ) ;
        dp[1] = 1, dp[2] = 2 ;

        // state transistion
        for( int i = 3 ; i <= n ; i++ ) {
            dp[i] = dp[i-1] + dp[i-2]  ;
        }

        // number of ways to climb at top
        return dp[n] ;
    }
};