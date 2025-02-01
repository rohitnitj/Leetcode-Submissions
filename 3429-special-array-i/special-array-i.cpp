class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size() ;
        if ( n == 1 ) return true ;
        if ( n == 2 ) return ( (nums[0]&1) != (nums[1]&1) ) ;

        for( int i = 1 ; i < n-1 ; i++) {
            bool a = nums[i-1] & 1 ;
            bool b = nums[i] & 1 ;
            bool c = nums[i+1] & 1 ;
            if ( ( a == b ) || ( b == c ) ) return false ;
        }
        return true ;
    }
};