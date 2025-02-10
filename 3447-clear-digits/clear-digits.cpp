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
        string ans = "" ;

        for( int i = 0 ; i < n ; i++ ) {
            if( isDigit(s[i]) ) ans.pop_back() ;
            else if( isChar(s[i] ) ) ans += s[i] ;
        }

        return ans ;
    }
};