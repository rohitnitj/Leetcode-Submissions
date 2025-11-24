class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size() ;

        vector<bool> ans(n) ;
        for( int i = 0 ; i < n; i++ ) {
            nums[i] += 2 * ( i ? nums[i-1] : 0 ) ;
            nums[i] %= 5 ;
            
            ans[i] = ( nums[i] % 5 ) ? false : true ;
        }

        return ans ; 
    }
};