class Solution {
public:
    int myAtoi(string s) {
        int n = s.size() ;
        long long num = 0 ;
        bool neg_sign = false  ;
        int i = 0 ;

        while( i < n && s[i] == ' ' ) i++ ;

        if( i < n && ( s[i] == '-' || s[i] == '+' )){
            neg_sign = ( s[i] == '-' ) ;
            i++ ;
        }

        while ( i < n && ( s[i] - '0' ) >= 0 && ( s[i] - '0' ) <= 9 ) {
            int curr = s[i] - '0' ;
            num = num * 10 + curr ;

            if( neg_sign && -num < INT_MIN ) return INT_MIN ;
            if( !neg_sign && num > INT_MAX ) return INT_MAX ;

            i++ ;
        }

        return neg_sign ? ( -1 * num ) : num ;
    }
};