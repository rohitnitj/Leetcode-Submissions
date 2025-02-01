class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int n = nums.size() ;
        int ans = 0 ;

        for( int i = 0 ; i < n ; i++ ) {
            int start = max(0, i- nums[i] ) ;
            
            for(int j = start ; j <= i ; j++ ) {
                ans += nums[j] ;
            }
        }

        return ans ;
    }
};