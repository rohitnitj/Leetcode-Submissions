class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size() ;

        vector<int> pre(n+1, 0 ) ;
        for( auto q : queries ) {
            pre[q[0]]-- ;
            pre[q[1]+1]++ ;
        }

        nums[0] += pre[0] ;
        if( nums[0] > 0 ) return false ;
        
        for( int i = 1 ; i < n ; i++ ) {
            pre[i] += pre[i-1] ;
            nums[i] += pre[i] ;

            if( nums[i] > 0 ) {
                return false ;
            }
        }

        return true ;
    }
};