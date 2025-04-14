class Solution {
private:
    int solve(int e, int f, vector<vector<int>>& dp) {
        if( f == 0 || f == 1 || e == 1 ) return dp[e][f] = f ;
        if( dp[e][f] != -1 ) return dp[e][f] ;
        int mimi = 1e8 ;

        for( int k = 1 ; k <= f ; k++ ) {
            int t1, t2 ;

            if( dp[e - 1][k - 1] != -1 ) t1 = dp[e - 1][k - 1] ;
            else t1 = solve( e - 1 , k - 1, dp) ;

            if( dp[e][f - k] != -1 ) t2 = dp[e][f - k] ;
            else t2 = solve( e , f - k, dp) ;

            int temp = 1 + max( t1 , t2 ) ;
            mimi = min( mimi , temp ) ;
        }

        return dp[e][f] = mimi ;
    }

    int eggDrop(int n, int k) {
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        return solve(n, k, dp) ;
    }

public:
    int twoEggDrop(int n) {
        return eggDrop(2, n ) ;
    }
};