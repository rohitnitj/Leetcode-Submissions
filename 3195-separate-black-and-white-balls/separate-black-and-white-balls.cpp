class Solution {
public:
    long long minimumSteps(string s) {
        long long swaps = 0 , zeroes = 0 ;

        for( int i = s.size()-1 ; i >= 0 ; i-- ) {
            if( s[i] == '1' ) swaps += zeroes ;
            else zeroes++ ;
        }      

        return swaps ;
    }
};
