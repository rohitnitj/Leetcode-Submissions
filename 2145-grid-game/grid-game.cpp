class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size() ;
        long long int lsum = 0, rsum = 0 ;
        for( int i = 0 ; i < n ; i++ ) {
            rsum += grid[0][i] ;
        }

        long long ans = LONG_LONG_MAX ;
        for( int i = 0 ; i < n ; i++ ) {
            rsum -= grid[0][i] ;
            ans = min(ans, max(lsum, rsum ) ) ;
            lsum += grid[1][i] ;
        }

        return ans ;
    }
};