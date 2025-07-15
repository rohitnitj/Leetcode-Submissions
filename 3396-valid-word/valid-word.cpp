class Solution {
public:
    bool isDigit(char ch ) {
        if( ch >= '0' && ch <= '9' ) return true ;
        return false ;
    }

    bool vowel(string word ) {
        for( char ch : word ) {
            if( ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || 
                ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' ) return true ;
        }
        return false ;
    }

    bool consonant(string word ) {
        for( char ch : word ) {
            if( !(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || 
                ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') && !isDigit(ch)) return true ;
        }
        return false ;
    }

    bool isAlNum(string word ) {
        for( char ch : word ) {
            if( (ch >= '0' && ch <= '9') || ( ch >= 'a' && ch <= 'z' ) || ( ch >= 'A' && ch <= 'Z' ) ) continue ;
            return false ; 
        }
        return true ;
    }

    bool isValid(string word) {
        int n = word.size() ;
        if( n >= 3 && isAlNum(word ) && vowel(word) && consonant(word ) ) return true ;
        return false ;
    }
};