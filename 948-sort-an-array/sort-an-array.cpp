class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size() ;   

        int maxi = -1e9, mini = 1e9 ;
        for( int i = 0 ; i < n ; i++ ) {
            maxi = max(maxi, nums[i] ) ;
            mini = min(mini, nums[i] ) ;
        }

        int m = maxi - mini ;

        vector<int> cnt(m+1, 0 ) ;
        for( int i = 0 ; i < n ; i++ ) {
            cnt[nums[i]-mini]++ ;
        }

        for(int i = 1 ; i <= m ; i++ ) {
            cnt[i] += cnt[i-1] ;
        }

        vector<int> ans(n ) ;
        for( int i = n-1 ; i >= 0 ; i-- ) {
            cnt[nums[i]-mini]-- ;
            ans[cnt[nums[i]-mini]] = nums[i] ;
        }

        return ans ;
    }
};