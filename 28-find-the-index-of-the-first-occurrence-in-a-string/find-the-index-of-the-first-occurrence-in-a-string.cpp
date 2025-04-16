class Solution {
public:
    int strStr(string haystack, string needle) {
        int n1 = haystack.size() ;
        int n2 = needle.size() ;

        for( int i = 0 ; i < n1 ; i++ ) {
            int p1 = i, p2 = 0 ;
            while( p1 < n1 && p2 < n2 ) {
                if( haystack[p1] != needle[p2] ) break ;
                p1++, p2++ ;
            }
            if( p2 == n2 ) return i ;
        }

        return -1 ;
    }
};