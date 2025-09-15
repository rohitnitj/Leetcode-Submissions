class Solution {
public:
    bool canForm(string word, string s ) {
        for( char w : word ) {
            for( char b : s ) {
                if( w == b ) return false ;
            }
        }
        return true ;
    }

    int canBeTypedWords(string text, string brokenLetters) {
        int cnt = 0 ;
        string temp = "" ;

        for( char ch : text ) {
            if( ch == ' ' ) {
                if( canForm(temp, brokenLetters ) ) cnt++ ;
                temp = "" ;
            }
            else temp += ch ;
        }

        if( canForm(temp, brokenLetters ) ) cnt++ ;

        return cnt ;
    }
};