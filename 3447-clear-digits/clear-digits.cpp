class Solution {
private:
    bool isChar(char ch ) {
        return ( ch >= 'a' && ch <= 'z' ) ;
    }

    bool isDigit(char ch ) {
        return ( ch >= '0' && ch <= '9' ) ;
    }

public:
    string clearDigits(string s ) {
        int n = s.size() ;
        int j = 0 ;

        for( int i = 0 ; i < n ; i++ ) {
            if( isDigit(s[i]) ) j-- ;
            else if( isChar(s[i] ) ) s[j++] = s[i] ;
        }

        s.resize(j) ;
        return s ;
    }
};