class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size() ;
        
        string a = "", b = "" ;
        int cnt = 0 ;
        for( int i = 0 ; i< n ; i++ ) {
            if( s1[i] != s2[i] ) {
                cnt++ ;
                a += s1[i] ;
                b += s2[i] ;
            }
        }

        if( cnt <= 2 ) {
            if( (a[0] == b[1]) && (b[0] == a[1]) ) return true ;
        }  

        return false ;
    }
};