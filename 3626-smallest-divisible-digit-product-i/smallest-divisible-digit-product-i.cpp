class Solution {
public:
    int findProductOfDigits( int n ) {
        string s = to_string(n) ; 
        int product = 1 ; 
        for( char ch : s ) {
            product *= ( ch - '0' ) ; 
        }
        return product ; 
    }

    int smallestNumber(int n, int t) {
        while( true ) {
            int product = findProductOfDigits(n) ; 
            if( product % t == 0 ) return n ; 
            n++ ; 
        }
        return n; 
    }
};