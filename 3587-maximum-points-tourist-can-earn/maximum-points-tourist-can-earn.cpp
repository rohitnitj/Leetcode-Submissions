class Solution {
public:
    int maxScore(int n, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) {
        vector<vector<int>> dp(k+1, vector<int> (n, 0 ) ) ;

        for( int i = 0 ; i < k ; i++ ) {
            for( int u = 0 ; u < n ; u++ ) {
                for( int v = 0 ; v < n ; v++ ) {
                    int score = u == v ? stayScore[i][u] : travelScore[u][v] ;
                    dp[i+1][v] = max( dp[i+1][v], dp[i][u] + score ) ;
                }
            }
        }

        int ans = dp[k][0] ;
        for( int i =1 ; i < n; i++ ) ans = max(ans, dp[k][i] ) ;
        return ans ;
    }
};