class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size() ;

        vector<int> bitCount(32, 0 ) ;
        int min_size = 1e9 ;
        int curr_or = 0 ;
        int left = 0 ;

        for( int right = 0; right < n; right++ ) {
            curr_or |= nums[right] ;
            
            for( int bit = 0 ; bit < 32 ; bit++ ) {
                if( nums[right] & ( 1 << bit )) bitCount[bit]++ ;
            }

            while( curr_or >= k && left <= right) {
                min_size = min(min_size, right - left + 1 ) ;
                int updated_or = 0 ;

                for( int bit = 0 ; bit < 32 ; bit++ ) {
                    if( nums[left] & ( 1 << bit ) ) bitCount[bit]-- ;
                    if( bitCount[bit] > 0 ) updated_or |= ( 1 << bit ) ;
                }

                curr_or = updated_or ;
                left++ ;
            }
        }

        return min_size == 1e9 ? -1 : min_size ;
    }
};