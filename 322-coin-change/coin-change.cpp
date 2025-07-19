class Solution {
public:

    // tabulation
    int minimumElements(vector<int> &num, int x){
        int n = num.size() ;
        vector<vector<int>> dp(n, vector<int> ( x+1, 0 ) ) ;

        for( int T = 0 ; T <= x ; T++ ) {
            if( T % num[0] == 0 ) dp[0][T] = T / num[0] ;
            else dp[0][T] = 1e9 ;
        }

        for( int ind = 1 ; ind < n ;ind++ ) {
            for( int T = 0 ; T <= x ; T++ ) {
                
                int notTake =  0 + dp[ind -1][T] ;
                int take = 1e9 ;
                if( num[ind] <= T ) {
                    take = 1 + dp[ind][T - num[ind]] ;
                }

                dp[ind][T] = min(take, notTake ) ;
            }
        }   
        
        int ans = dp[n-1][x] ;
        if( ans >= 1e9 ) return -1 ;
        return ans ;
    }

    int coinChange(vector<int>& coins, int amount) {
        return minimumElements(coins, amount ) ;
    }
};