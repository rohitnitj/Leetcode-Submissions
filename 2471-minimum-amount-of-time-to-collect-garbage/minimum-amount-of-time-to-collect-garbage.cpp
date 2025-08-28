class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size() ;

        vector<int> pre(n ) ;
        for( int i = 1; i < n ; i++ ) pre[i] += pre[i-1] + travel[i-1] ;

        int cg = 0, cp = 0, cm = 0 ;
        int lg = 0, lp = 0, lm = 0 ;

        for( int i = 0 ; i < n ; i++ ) {
            for( char ch : garbage[i] ) {
                if( ch == 'G' ) {
                    cg++ ;
                    lg = i ;
                }
                else if( ch == 'P' ) {
                    cp++ ;
                    lp = i ;
                }
                else {
                    cm++ ;
                    lm = i ;
                }
            }
        }

        int ans = cg + cp + cm + pre[lg] + pre[lp] + pre[lm] ;
        return ans ;
    }
};
