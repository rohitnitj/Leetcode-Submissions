class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size() ;
        sort(nums.begin(), nums.end() ) ;

        int cnt = 0 ;
        int i = 0, j = 0 ;
        while( i < n && j < n ) {
            while( j < n && ( nums[j] - nums[i] <= k ) ) j++ ;
            cnt++ ;
            i = j ;
        }

        return cnt ;
    }
};