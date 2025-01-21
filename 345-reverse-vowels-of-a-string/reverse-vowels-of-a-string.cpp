class Solution {
private:
    bool isVowel( char ch ) {
        vector<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' } ;
        for( int i = 0 ; i < 10 ; i++ ) {
            if( vowels[i] == ch ) return true ;
        }
        return false ;
    }

public:
    string reverseVowels(string s) {
        int n = s.size() ;   
        int i = 0 , j = n-1;

        while( i < j  ) {
            while( i < n && !isVowel(s[i]) ) i++ ;
            while( j >= 0 && !isVowel(s[j]) ) j-- ;

            if( i < j ) {
                swap(s[i], s[j]) ;
                i++ , j-- ;
            }
        }   

        return s ;
    }
};