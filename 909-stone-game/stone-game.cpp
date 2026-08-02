class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size() ; 

        vector<vector<int>> dp(n+2, vector<int>(n+2 ) ) ; 

        for( int size = 1; size <= n ; size++ ) {
            for( int i = 0; i < n ; i++ ) {
                int j = i + size - 1; 
                if( j >= n ) break ; 

                int parity = ( (j + i + n) & 1 ) ; 
                if( parity ) dp[i+1][j+1] = max( piles[i] + dp[i+2][j+1], piles[j] + dp[i+1][j] ) ; 
                else dp[i+1][j+1] = min( -piles[i] + dp[i+2][j+1], -piles[j] + dp[i+1][j] ) ; 
            }
        }

        return dp[1][n] > 0 ; 
    }
};