class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size() ;
        if( n == 1 || n == 2 ) return n ;

        int cnt = 0 ;
        while( n >> 1 ) {
            n >>= 1 ;
            cnt++ ;
        }

        return ( 1 << (cnt+1) ) ;
    }
};
