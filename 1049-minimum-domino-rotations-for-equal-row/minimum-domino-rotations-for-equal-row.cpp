class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();

        int t = tops[0], b = bottoms[0] ;
        int ans = 1e8, cnt = 0 ;
        bool f = true ;

        for( int i = 0 ; i < n ; i++ ) {
            if( tops[i] == t ) continue ;
            else if(  bottoms[i] == t ) cnt++ ;
            else {
                f = false ;
                break ;
            }
        }

        if( f ) ans = min(ans, cnt ) ;
        cnt = 0, f = true ;

        for( int i = 0 ; i < n ; i++ ) {
            if( bottoms[i] == t ) continue ;
            else if( tops[i] == t ) cnt++ ;
            else {
                f = false ;
                break ;
            }
        }

        if( f ) ans = min(ans, cnt ) ;
        cnt = 0 , f = true ;

        for( int i = 0 ; i < n ; i++ ) {
            if( tops[i] == b ) continue ;
            else if( bottoms[i] == b ) cnt++ ;
            else {
                f = false ;
                break ;
            }
        }

        if( f ) ans = min(ans, cnt ) ;
        cnt = 0, f = true ;

        for( int i = 0 ; i < n ; i++ ) {
            if( bottoms[i] == b ) continue ;
            else if( tops[i] == b ) cnt++ ;
            else {
                f = false ;
                break ;
            }
        }
        
        if( f ) ans = min(ans, cnt ) ;

        return ans == 1e8 ? -1 : ans ;
    }
};