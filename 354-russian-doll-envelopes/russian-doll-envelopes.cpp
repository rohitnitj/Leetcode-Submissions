class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort( envelopes.begin(), envelopes.end(), []( auto &a, auto &b ) {
            if( a[0] == b[0] ) return a[1] > b[1] ;
            return a[0] < b[0] ;
        });

        vector<int> H ;
        for( auto &e : envelopes ) H.push_back( e[1] ) ;

        vector<int> dp;
        for( int h : H ) {
            auto it = lower_bound( dp.begin(), dp.end(), h ) ;
            if( it == dp.end() ) dp.push_back(h) ;
            else *it = h ;
        }

        return dp.size() ;
    }
};
