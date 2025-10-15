class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size() ;

        vector<int> arr(n, 1 ) ;
        for( int i = 1 ; i < n; i++ ) {
            if( nums[i] > nums[i-1] ) arr[i] += arr[i-1] ;
        }

        int maxi = 0, ans = 0 ;
        for( int i = 1; i < n; i++ ) {
            maxi = max(maxi, arr[i] ) ;
            int idx = i - arr[i] ;
            if( idx >= 0 ) ans = max(ans, min(arr[i], arr[idx] )) ;
        }

        ans = max(ans, maxi / 2 ) ;
        return ans ; 
    }
};