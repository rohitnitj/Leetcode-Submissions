class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num) ;
        string s1 = s, s2 = s ;
        int n = s.size() ;

        char val1, val2 ;
        for( int i = 0 ; i < n ; i++ ) {
            if( s[i] != '9' ) {
                val1 = s[i] ;
                break ;
            }
        }

        for( int i = 0 ; i < n ; i++ ) {
            if( s[i] != '0' ) {
                val2 = s[i] ;
                break ;
            }
        }

        for( int i = 0 ; i < n ; i++ ) {
            if( s1[i] == val1 ) s1[i] = '9' ;
            if( s2[i] == val2 ) s2[i] = '0' ;
        }

        int n1 = stoi(s1), n2 = stoi(s2 ) ;
        return n1 - n2 ;
    }
};