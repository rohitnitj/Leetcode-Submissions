class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxi = INT_MIN, mini = INT_MAX ;
        int psum = 0 ;

        for(int num : nums ) {
            psum += num ; 
            maxi = max(maxi, psum ) ;
            mini = min(mini, psum ) ;
        }

        int ans = maxi - mini ;
        if( abs( maxi ) > ans ) ans = abs(maxi ) ;
        if( abs( mini ) > ans ) ans = abs(mini ) ;

        return ans ;

    }
};