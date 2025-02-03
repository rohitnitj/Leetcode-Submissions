class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size() ;
        int ans = 1 ;

        for( int i = 0 ; i < n -1 ; i++ ) {
            for(int j = i ; j < n -1 ; j++ ) {
                if( nums[j+1] >= nums[j] ){
                    ans = max(ans, j-i+1 ) ;
                    break ;
                }
                ans = max( ans, j-i+2 ) ;
            }

            for( int j = i ; j < n-1 ; j++) {
                if( nums[j+1] <= nums[j] ) {
                    ans = max(ans, j-i+1 ) ;
                    break ;
                }
                ans = max( ans, j-i+2 ) ;
            }
        }

        return ans ;
    }
};