class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size() ;
        int zero = 0 , prod = 1 ;
        
        for( auto num : nums ) {
            if( num == 0 ) {
                zero++ ;
            }
            else {
                prod *= num ;
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