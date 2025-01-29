class Solution {
private:
    int func(int n, vector<int> &dp ) {
        if( dp[n] != -1 ) return dp[n] ;
        if( n == 0 ) return dp[n] = 0 ;
        else if( n == 1 || n == 2 ) return dp[n] = 1 ;
        return dp[n] = func(n-1, dp ) + func(n-2, dp) + func(n-3, dp) ;
    }

public :
    int tribonacci(int n ) {
        vector<int> dp(n+1, -1 ) ;
        return func(n, dp ) ;
    }
};