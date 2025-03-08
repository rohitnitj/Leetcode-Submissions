class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size() ;
        int b = 0, w = 0 ;
        int i = 0, j = 0 ;

        for( j = 0 ; j < k ; j++ ) {
            if( blocks[j] == 'W' ) w++ ;
            if( blocks[j] == 'B' ) b++ ;
            // cout << "j: " << j << " w: " << w << " b: " << b << endl ;
        }

        if( b == k ) return 0 ;
        int ans = w ;
        // cout << "ans : " << ans << endl ;

        while( j < n ) {
            if( blocks[i] == 'W' ) w-- ;
            else b-- ;
            if( blocks[j] == 'W' ) w++ ;
            else b++ ;

            i++, j++ ;
            ans = min(ans, w ) ;
            // cout << "w: " << w << " b: " << b << " ans : " << ans << endl ;
        }
        
        return ans ;
    }
};