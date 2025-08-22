class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size() ;

        int top = n-1, bottom = 0;
        int left = m-1, right = 0;

        for( int i = 0 ; i < n ; i++ ) {
            for( int j = 0 ; j < m ; j++ ) {
                if( grid[i][j] ) {
                    top = min( top, i ) ;
                    bottom = max( bottom, i ) ;
                    left = min( left, j ) ;
                    right = max( right, j ) ;
                }
            }
        }

        if( top > bottom || left > right ) return 0 ;

        int ans = ( right - left + 1 ) * ( bottom - top + 1 ) ;
        return ans ;
    }
};