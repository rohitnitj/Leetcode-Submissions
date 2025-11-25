class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int rem = 0 ;
        for( int ln = 1 ; ln <= k ; ln++ ) {
            rem = ( rem * 10 + 1 ) % k ;
            if( rem == 0 ) return ln ; 
        }
        return -1 ;
    }
};