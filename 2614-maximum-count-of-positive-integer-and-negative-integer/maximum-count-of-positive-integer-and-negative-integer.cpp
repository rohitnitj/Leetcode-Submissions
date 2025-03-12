class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size() ; 
        int i = 0 ;
        int neg = 0 ;
        for( i = 0 ;i < n ; i++ ) {
            if( nums[i] < 0 ) neg++ ;
            else if( nums[i] == 0 ) continue ;
            else break ;
        }
        int pos = n-i ;
        return max(neg, pos ) ;
    }
};