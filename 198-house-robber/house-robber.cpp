class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size() ;

        // base case
        if( n == 1 ) return nums[0];
        if( n == 2 ) return max(nums[0], nums[1] ) ;

        // dp[i] = max money till index i 
        vector<int> dp(n) ;
        dp[0] = nums[0] ;
        dp[1] = max(nums[0], nums[1] ) ;

        // transition : take or not Take
        for( int i = 2 ; i < n ; i++ ) {
            dp[i] = max(nums[i] + dp[i-2], dp[i-1] ) ;
        }

        return dp[n-1] ;
    }
};