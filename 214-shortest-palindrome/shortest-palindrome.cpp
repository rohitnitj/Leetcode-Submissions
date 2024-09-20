class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.length() ;

        string t = s ;
        reverse(t.begin(), t.end() );

        string l = s + "*" + t ;
        vector<int> p(l.size(), 0 ) ;

        for( int i = 1; i < l.size() ; i++ ) {
            int j = p[i-1] ;

            while( j > 0 && l[i] != l[j] ) 
                j = p[j-1] ;

            if( l[i] == l[j] ) 
                j++ ;
                
            p[i] = j ; 
        }

        return t.substr(0, s.size() - p.back() ) + s ;
    }
};