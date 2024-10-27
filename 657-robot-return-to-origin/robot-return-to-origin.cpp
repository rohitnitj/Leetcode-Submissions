class Solution {
public:
    bool judgeCircle(string moves) {
        int l = 0, r = 0 , u = 0 , d = 0 ;

        for( auto ch : moves ) {
            if( ch == 'L' ) l++ ;
            if( ch == 'R' ) r++ ;
            if( ch == 'U' ) u++ ;
            if( ch == 'D' ) d++ ;
        }

        return ( l == r && u == d ) ;
    }
};