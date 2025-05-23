class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size() ;
        vector<int> ans ;

        for( int i = 0 ; i < n-1 ; i++ ) {
            if( nums[i] == nums[i+1] && nums[i] != 0 ) {
                ans.push_back(2*nums[i] ) ;
                i++ ;
            }
            else if( nums[i] != 0 ) {
                ans.push_back(nums[i] ) ;
            }
        }
        
        if( nums[n-1] != 0 && nums[n-1] != nums[n-2] ) ans.push_back(nums[n-1] ) ;

        while( ans.size() != n ) ans.push_back(0) ;
        return ans ;
    }
};