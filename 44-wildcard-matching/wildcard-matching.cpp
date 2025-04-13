class Solution {
public:
    bool isMatch(string t, string p) {
        int n = p.size() ;
        int m = t.size() ;

        vector<bool> prev(m+1, false ) ;
        vector<bool> curr(m+1, false ) ;
        prev[0] = true ;

        for( int j = 1; j <= m ; j++ ) {
            prev[j] = false ;
        }

        for( int i = 1 ; i <= n ; i++ ) {

            curr[0] = ( p[i-1] ==  '*' ) ? prev[0] : false ;

            for (int j = 1 ; j <= m ; j++ ) {

                if( p[i-1] == t[j-1] || p[i-1] == '?' ) {
                    curr[j] = prev[j-1] ;
                }
                else if ( p[i-1] == '*' ) {
                    curr[j] = prev[j] | curr[j-1] ;
                }
                else
                    curr[j] = false ;
            }

            prev = curr ;
        }

        return prev[m] ;
    }
};