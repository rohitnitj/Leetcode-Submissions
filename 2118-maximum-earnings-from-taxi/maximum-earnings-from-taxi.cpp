typedef long long ll ;
class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {

        sort(rides.begin(), rides.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        vector<ll> dp(n+1, 0 ) ;
        int j = 0 ;

        for( int i = 1 ; i <= n ; i++ ) {
            dp[i] = dp[i-1] ;

            while( j < rides.size() && rides[j][1] == i ) {
                int start = rides[j][0] ;
                int end = rides[j][1] ;
                int tip = rides[j][2] ;
                dp[i] = max(dp[i], dp[start] + end - start + tip ) ;
                j++ ;
            }
        }

        return dp[n] ;
    }
};