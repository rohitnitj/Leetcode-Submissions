class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end()) ;
        int n = nums.size();
        int i = 0, j = n-1, cnt = 0 ;
        while( i < j ) {
            int sum = nums[i] + nums[j] ;
            if( sum == k ) {
                i++;
                j--;
                cnt++ ;
            }
            if( sum < k ) i++ ;
            if( sum > k ) j-- ;
        }
        return cnt ;
    }
};