class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size() ;
        vector<int> diff(n+1, 0) ;

        for( auto shift : shifts ) {
            int s = shift[0], e = shift[1], d = shift[2] ;
            if( d == 0 ) {
                diff[s]-- ;
                diff[e+1]++ ;
            }
            else{
                diff[s]++ ;
                diff[e+1]-- ;
            }
        }

        for( int i = 1 ; i < n+1 ; i++ ) {
            diff[i] += diff[i-1] ;
        }

        for( int i = 0 ; i < n ; i++ ) {
            int d = diff[i] % 26 ;
            if( d < 0  ) d += 26 ;
            s[i] = 'a' + ( s[i] - 'a' + d ) % 26 ;
        }

        return s ;
    }
};