class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size() ;

        int i = 0 , sum = 0, ans = 1e9 ;
        for( int j = 0 ; j < n ; j++ ) {
            sum += nums[j] ;

            while( sum >= target ) {
                ans = min(ans, j - i + 1 ) ;
                sum -= nums[i] ; 
                i++ ;
            }
        }

        return ( ans == 1e9 ? 0 : ans ) ;
    }
};