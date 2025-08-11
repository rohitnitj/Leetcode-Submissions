class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size() ;
        
        vector<int> ans ;
        for( int i = 0 ; i < n ; i++ ) {
            if( nums[i] != i ) ans.push_back(nums[i] ) ; 
        }

        if( ans.size() == 0 ) return 0 ;

        int val = ans[0];
        for( int a : ans ) val &= a ;
        return val ;
    }
};
