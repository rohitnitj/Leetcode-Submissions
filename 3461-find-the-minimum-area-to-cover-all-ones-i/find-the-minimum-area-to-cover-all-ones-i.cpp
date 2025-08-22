class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size() ;

        int top = 0, bottom = n-1 ;
        int left = 0, right = m-1 ;

        for( int i = 0 ; i < n ; i++ ) {
            top = i ;
            bool f = false ;
            for( int j = 0 ; j < m ; j++ ) {
                if( grid[i][j] == 1 ) f = true ;
            }
            if( f ) break ;
        }

        for( int i = n-1 ; i >= 0 ; i-- ) {
            bottom = i ;
            bool f = false ;
            for( int j = 0 ; j < m ; j++ ) {
                if( grid[i][j] == 1 ) f = true ;
            }
            if( f ) break ;
        }

        for( int j = 0 ; j < m ; j++ ) {
            left = j ;
            bool f = false ;
            for( int i = 0 ; i < n ; i++ ) {
                if( grid[i][j] == 1 ) f = true ;
            }
            if( f ) break ;
        }        

        for( int j = m-1 ; j >= 0 ; j-- ) {
            right = j ;
            bool f = false ;
            for( int i = 0 ; i < n ; i++ ) {
                if( grid[i][j] == 1 ) f = true ;
            }
            if( f ) break ;
        }

        if( top > bottom || left > right ) return 0 ;

        int ans = ( right - left + 1 ) * ( bottom - top + 1 ) ;
        return ans ;
    }
};
