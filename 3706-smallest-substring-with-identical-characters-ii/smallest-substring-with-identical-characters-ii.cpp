class Solution {
public:
    bool canTransformAlt(string &s, int k, int target, char start ) {
        for( char ch : s ) {
            if( ch == start ) k-- ;
            start ^= 1 ;
        }
        return ( k >= 0 ) ;
    }

    bool isPossible(string &s, int k, int maxLen ) {
        if( maxLen == 1 ) {
            return canTransformAlt(s, k, maxLen, '1' ) || canTransformAlt(s, k, maxLen, '0' ) ; 
        }

        int repCnt = 0 ;
        for( int i = 0, lastChar = -1 ; i < s.size() ; i++ ) {
            if( s[i] == lastChar ) {
                repCnt++ ;
            }
            else{
                k -= repCnt / ( maxLen + 1 ) ;
                lastChar = s[i] ;
                repCnt = 1 ;
            }
        }

        k -= repCnt / ( maxLen + 1 ) ;
        return ( k >= 0 ) ;
    }

    int minLength(string s, int numOps) {
        int left = 1, right = s.size(), ans = s.size() ;
        while( left <= right ) {
            int mid = left + ( right - left ) / 2;
            if( isPossible(s, numOps, mid ) ) {
                ans = mid ;
                right = mid -1 ;
            }
            else {
                left = mid + 1 ;
            }
        }
        return ans ;
    }
};