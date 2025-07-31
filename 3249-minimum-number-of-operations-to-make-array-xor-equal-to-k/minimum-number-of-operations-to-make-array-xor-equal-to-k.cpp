class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int xr = 0 ;
        for( int a : nums ) xr ^= a ;
        xr ^= k ;

        int cnt = 0 ;
        for( int i = 0 ; i < 30 ; i++ ) {
            if( xr & ( 1 << i ) ) cnt++ ;
        }

        return cnt ;
    }
};