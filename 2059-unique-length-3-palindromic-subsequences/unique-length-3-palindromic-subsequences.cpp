class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char> letters ;
        for( char c : s ) {
            letters.insert(c) ;
        }

        int cnt = 0 ;
        for( char letter : letters ) {
            int i = -1 ;
            int j = 0 ;

            for( int k = 0 ; k < s.size() ; k++ ) {
                if( s[k] == letter ) {
                    if( i == -1 ) {
                        i = k ; 
                    }
                    j = k ;
                }
            }

            unordered_set<char> unique ;
            for( int k = i+1 ; k < j ; k++ ) {
                unique.insert(s[k] ) ;
            }

            cnt += unique.size() ;
        }

        return cnt ;
    }
};