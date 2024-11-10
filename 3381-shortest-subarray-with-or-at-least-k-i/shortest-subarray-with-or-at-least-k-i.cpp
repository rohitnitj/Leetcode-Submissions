class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size() ;
        int min_size = INT_MAX ;      

        for( int i = 0 ;i < n ; i++ ) {
            int curr_or = 0 ;

            for( int j = i ; j < n ; j++ ) {
                curr_or |= nums[j] ;

                if( curr_or >= k ) {
                    min_size = min(min_size, j-i+1 ) ;
                    break ;
                }
            }
        }

        return min_size == INT_MAX ? -1 : min_size ;
    }
};