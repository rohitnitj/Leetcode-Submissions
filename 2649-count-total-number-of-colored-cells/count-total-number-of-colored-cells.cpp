typedef long long ll ;

class Solution {
private:
    ll f(int n, vector<ll> &dp ) {
        if( n == 1) return ll(1) ;
        if( dp[n] != -1 ) return dp[n] ;
        return dp[n] = ll((ll)4*(n-1) + f(n-1, dp )) ;
    }

public:
    long long coloredCells(int n ) {
        vector<ll> dp(n+1, -1) ;
        return f(n, dp ) ;
    }
};