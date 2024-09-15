class Solution {
private:    
    #define ll long long
    vector<vector<ll>> dp ;
    int n ;

    ll helper(int ind, int g, vector<int> &a , vector<int> &b ){
        if( g == 4 ) return 0 ;
        if( ind == n ) return -1e12 ;
        if( dp[ind][g] != -1e12 ) return dp[ind][g] ;

        ll ans1 = helper(ind+1, g, a, b ) ;
        ll ans2 = helper(ind+1, g+1, a, b ) + a[g] * 1LL * b[ind] ;

        return dp[ind][g] = max(ans1, ans2 ) ;
    }

public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        n = b.size() ;
        dp = vector<vector<ll>> (n, vector<ll> (4, -1e12 ) ) ;
        return helper(0,0,a,b) ;
    }
};