#define ll long long

class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        int n = nums.size() ;
        
        if( n == 1 ) return nums[0] ;

        vector<ll> dp( n + 1, 0 ) ;

        dp[0] = nums[0] ;
        if( colors[0] == colors[1] ) dp[1] = max( nums[0], nums[1] ) ;
        else dp[1] = dp[0] + nums[1] ;

        for( int i = 2 ; i < n; i++ ) {
            if( colors[i] == colors[i-1] ) dp[i] = max( nums[i] + dp[i-2], dp[i-1] ) ;
            else dp[i] = dp[i-1] + nums[i] ;
        }

        return dp[n-1] ;
    }
};
