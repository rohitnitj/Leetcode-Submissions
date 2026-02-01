class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size() ;

        for( int i = 0 ; i < n - 3; i++ ) {
            int a = nums[i], b = nums[i+1] , c = nums[i+2], d = nums[i+3]  ;
            if( a == b || a == c || a == d ) return a ;
            else if( b == c || b == d ) return b ;
            else if( c == d ) return c ; 
        }

        return -1 ;
    }
};