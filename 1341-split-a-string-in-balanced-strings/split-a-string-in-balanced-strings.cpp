class Solution {
public:
    int balancedStringSplit(string s) {
        int n = s.size() ;
        int cnt = 0, ans = 0 ;
        for( char ch : s ) {
            if( ch == 'L' ) cnt-- ;
            else if( ch == 'R' ) cnt++ ;
            if( cnt == 0 ) ans++ ;
        }
        return ans ;
    }
};