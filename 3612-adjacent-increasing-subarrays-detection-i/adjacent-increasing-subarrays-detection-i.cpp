class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size() ;
  
        vector<int> arr(n, 1) ; 
        for( int i = 1; i < n; i++ ) {
            if( nums[i] > nums[i-1] ) arr[i] += arr[i-1] ;
        }

        for( int a : arr ) cout << a << " " ;
        
        for( int i = 0 ; i < n ; i++ ) {
            if( arr[i] >= k ) {
                int idx = i - k ;
                if( idx >= 0 && arr[idx] >= k ) return true ;
            }
        }

        return false ;
    }
};