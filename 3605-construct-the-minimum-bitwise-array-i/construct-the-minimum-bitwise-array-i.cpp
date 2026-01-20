class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size() ;

        vector<int> ans(n, -1 ) ;
        for( int i = 0; i < n ; i++ ) {
            for( int val = 0 ; val < nums[i] ; val++ ) {
                if( ( val | ( val + 1 ) ) == nums[i] ) {
                    ans[i] = val ;
                    break ;
                }
            }
        }

        return ans ;
    }
};