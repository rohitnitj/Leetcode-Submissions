class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size() ;
        int prod = 1 , zero = 0 ;
        for( auto num : nums ){
            if( num != 0 ) {
                prod *= num ;
            }
            else{
                zero++ ;
            }
        }

        vector<int> ans(n, 0 ) ;
        
        if( zero >= 2 ) return ans ;

        for( int i = 0 ; i < n ; i++ ) {
            if( zero == 1 ) {
                if( nums[i] == 0 ) {
                    ans[i] = prod ;
                }
                else {
                    ans[i] = 0 ;
                }
            }
            else{
                ans[i] = prod / nums[i] ;
            }
        }

        return ans ;
    }
};