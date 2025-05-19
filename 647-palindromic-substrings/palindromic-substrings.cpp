class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size() ;
        int cnt = 0 ;

        for( int i = 0 ; i < n ; i++ ) {
            string temp = "" ;

            for( int j = i ; j < n ; j++ ) {
                temp += s[j] ;

                string t2 = temp ;
                reverse(t2.begin(), t2.end()) ;
                if( temp == t2 ) cnt++ ;                    
            }
        }

        return cnt ;
    }
};