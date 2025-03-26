class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size() ;
        sort(nums.begin(), nums.end() ) ;
        
        int ans = 0 ;
        int m = nums.size() / 2 ;
        int mid = nums[m] ;

        for( auto a : nums ) {
            ans += abs( a - mid ) ;
        }

        return ans ;
    }
};