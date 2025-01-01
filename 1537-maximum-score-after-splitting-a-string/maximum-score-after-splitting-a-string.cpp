class Solution {
public:
    int maxScore(string s) {
        int n = s.size() ;
        int one = 0 ;
        int zero = 0 ;

        if( s[0] == '0' ) zero++ ;

        for( int i = 1 ; i < n ; i++ ) {
            if( s[i] == '1' ) one++ ;
        }

        int maxi = one + zero  ;
        
        for( int i = 1 ; i < n-1 ; i++ ) {
            if( s[i] == '0' ) zero++ ;
            else if( s[i] == '1') one-- ;
            maxi = max(maxi, zero + one ) ;
        }

        return maxi ;
    }
};