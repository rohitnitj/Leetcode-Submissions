class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n = nums.size() ;
        int ans = -1 ;

        if( n == 1 && ( k & 1)) return -1 ;

        for( int i = 0 ; i < n ; i++ ) {
            if( i == k + 1 ) break ;
            if( i == k - 1 ) continue ;
            ans = max(ans, nums[i] ) ;
        }

        return ans ;
    }
};