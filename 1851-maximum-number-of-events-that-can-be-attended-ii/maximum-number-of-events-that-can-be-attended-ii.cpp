class Solution {
public:
    static int bisectRight( const vector<vector<int>> &events, int target ) {
        int left = 0, right = events.size() ;
        while( left < right ) {
            int mid = ( left + right ) / 2 ;
            if( events[mid][0] <= target ) left = mid + 1 ;
            else right = mid ;
        }
        return left ;
    }

    int maxValue(std::vector<std::vector<int>>& events, int k) {
        int n = events.size() ;
        sort( events.begin(), events.end(),[](const vector<int> &a, const vector<int> &b ) {
            return a[0] < b[0] ;
        } ) ;

        vector<vector<int>> dp(k+1, vector<int>(n+1, 0 ) ) ;
        for( int curr = n-1 ; curr >= 0 ; curr-- ) {
            for( int cnt = 1 ; cnt <= k ; cnt++ ) {
                int nextIdx = bisectRight(events, events[curr][1] ) ;
                dp[cnt][curr] = max(dp[cnt][curr+1], events[curr][2] + dp[cnt-1][nextIdx] ) ;
            }
        }

        return dp[k][0] ;
    }
};