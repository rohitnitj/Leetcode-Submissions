// TC : O( N * log(N) ) 
class Solution {
private:
    long long lower_bound(vector<int> &nums, int low, int high, int element ) {

        while( low <= high ) {
            int mid = low + ( high - low ) / 2 ;
            if( nums[mid] >= element ) high = mid - 1 ;
            else low = mid + 1 ;
        }

        return low ;
    }

public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size() ;

        long long cnt = 0 ;
        sort(nums.begin(), nums.end() ) ;

        for(int i = 0 ; i < n; i++ ) {
            long long left = lower_bound(nums, i+1, n-1, lower-nums[i] ) ;
            long long right = lower_bound(nums, i+1, n-1, upper-nums[i]+1) ;
            cnt += ( right - left ) ;
        }

        return cnt ;
    }
};