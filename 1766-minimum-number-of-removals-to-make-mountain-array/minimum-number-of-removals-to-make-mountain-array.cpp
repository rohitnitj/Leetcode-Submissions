class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size() ;
        
        vector<int> lis(n, 1 ) ;  // Longest Increasing Subsequence
        vector<int> lds(n, 1 ) ;  // Longest Decreasing Subsequence

        for(int i = 0 ; i < n; i++ ) {
            for( int j = i-1 ; j >= 0 ; j-- ) {
                if( nums[i] > nums[j] ) {
                    lis[i] = max( lis[i], lis[j] + 1 ) ;
                }
            }
        }

        for( int i = n-1 ; i >= 0 ; i-- ) {
            for( int j = i+1 ; j < n ; j++ ) {
                if( nums[i] > nums[j] ) {
                    lds[i] = max( lds[i], lds[j] + 1 ) ;
                }
            }
        }

        int ans = 1e9 ;
        for( int i = 0 ; i < n ; i++ ) {
            if( lds[i] > 1 && lis[i] > 1 ) {
                
                // int left = ( i + 1 ) - lis[i] ;
                // int right = ( n - 1 ) - lds[i] ;
                // int total = left + right = n+1-lis[i]-lds[i] ;

                ans = min( ans, n+1-lis[i]-lds[i] ) ;
            }
        }

        return ans ;
    }
};
