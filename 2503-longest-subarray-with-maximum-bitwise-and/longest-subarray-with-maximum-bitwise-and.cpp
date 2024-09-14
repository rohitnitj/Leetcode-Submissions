// Rohit Kumar Gupta
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size() ;
        int ans = 0 ;
        int size = 0 ;

        int max_val = nums[0] ;
        for( int val : nums ) max_val = max(max_val, val ) ;

        for( int i = 0 ; i < n; i++ ) {
            if( nums[i] == max_val ) {
                size++ ;
                ans = max(ans, size) ;
            }
            else{
                size = 0 ;
            }
        }

        return ans ;
    }
};
