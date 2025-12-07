class Solution {
public:
    int countOdds(int low, int high) {
        int ans = ( high - low ) / 2 ;

        int l = low & 1 ;
        int r = high & 1 ;

        return ( l || r ? ans + 1 : ans ) ; 
    }
};