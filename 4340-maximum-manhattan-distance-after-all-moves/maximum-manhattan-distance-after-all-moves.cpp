class Solution {
public:
    int maxDistance(string moves) {
        int horizontal = 0, vertical = 0, any = 0 ; 
        for( char ch : moves ) {
            if( ch == 'R' ) horizontal++ ; 
            else if( ch == 'L' ) horizontal-- ;
            else if( ch == 'U' ) vertical++ ; 
            else if( ch == 'D' ) vertical-- ; 
            else any++ ; 
        }

        int ans = abs( horizontal ) + abs( vertical ) + any ; 
        return ans ; 
    }
};