class Solution {
public:
    bool isVowel(char val ) {
        for( char ch : { 'a', 'e', 'i', 'o', 'u' } ) {
            if( ch == val ) return true ;
        }
        return false ;
    }

    bool doesAliceWin(string s) {
        int cnt = 0 ;
        for( char ch : s ) cnt += isVowel(ch ) ;
        return cnt ;
    }
};