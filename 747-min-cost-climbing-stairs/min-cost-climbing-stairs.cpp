class Solution {
private: 
    int f( vector<int> &cost, int n, vector<int> &dp ) {
        if( n < 0 ) return 0 ;
        if( n == 0 || n == 1 ) return cost[n] ;
        if( dp[n] != -1 ) return dp[n] ;
        
        int one = f(cost, n-1, dp ) ;
        int two = f(cost, n-2, dp ) ;
        return dp[n] = cost[n] + min(one, two ) ;
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size() ;
        vector<int> dp(n, -1 ) ;
        return min( f(cost, n-1, dp ), f(cost, n-2, dp ) )  ;
    }
};