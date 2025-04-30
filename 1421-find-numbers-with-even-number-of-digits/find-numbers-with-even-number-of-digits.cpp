class Solution {
public:
    bool f(int n ) {
        int c = 0 ;
        while( n ) {
            c++ ;
            n /= 10 ;
        }
        return c%2 == 0 ? true : false ;
    }

    int findNumbers(vector<int>& nums) {
        int cnt = 0 ;
        for( int num : nums ) {
            if( f ( num ) ) cnt++ ;
        }
        return cnt ;
    }
};