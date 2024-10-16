class Solution {
public:
    int monotoneIncreasingDigits(int n) {

        if( n == 0 ) return 0 ;
        
        string s = to_string(n) ;
        int size = s.size() ;
        int flag = n-1 ;

        for( int i = size-1 ; i > 0 ; i--) {
            if( s[i-1] > s[i] ) {
                flag = i-1 ;
                s[i-1]-- ;
            }
        }

        for( int i = flag+1 ; i < size ; i++ ) {
            s[i] = '9' ;
        }

        return stoi(s) ;
    }
};