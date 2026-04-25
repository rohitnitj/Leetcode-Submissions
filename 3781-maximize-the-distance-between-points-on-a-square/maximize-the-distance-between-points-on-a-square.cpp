typedef long long ll ;

class Solution {
public :
    ll map(int side, int x, int y ) {
        if( y == 0 ) return x ;
        if( x == side ) return side + y ;
        if( y == side ) return 3ll * side - x ;
        return 4ll * side - y ;
    }

    bool check(vector<ll> &t, int k, int side, int d ) {
        int n = t.size() ;
        ll L = 4ll * side ;
        vector<ll> extended(2*n ) ;

        for( int i = 0 ; i < n ; i++ ) {
            extended[i] = t[i] ;
            extended[i+n] = t[i] + L ;
        }

        for( int i = 0 ; i < n ; i++ ) {
            int count = 1 ;
            ll pos = extended[i] ;
            int idx = i ;

            for( int cnt = 1; cnt < k ; cnt++ ) {
                ll target = pos + d ;
                auto it = lower_bound(extended.begin() + idx + 1, extended.begin() + i + n , target ) ;

                if( it == extended.begin() + i + n ) {
                    count = -1 ;
                    break; ;
                }
                
                idx = it - extended.begin() ;
                pos = extended[idx] ;
                count++ ;
            }

            if( count == k && ( extended[i] + L - pos ) >= d ) return true ;
        }

        return false ;
    }

    int maxDistance(int side, vector<vector<int>> &points, int k ) {
        int n = points.size() ;
        vector<ll> t(n) ;
        
        for( int i = 0 ; i < n ; i++ ) {
            int x = points[i][0], y = points[i][1] ;
            t[i] = map(side, x, y ) ;
        }

        sort(t.begin(), t.end() ) ;
        int l = 0, h = 2*side, ans = 0 ;

        while( l <= h ) {
            int m = l + ( h - l ) / 2 ;

            if( check(t, k, side, m ) ) {
                ans = m ;
                l = m + 1 ;
            }
            else {
                h = m - 1 ;
            }
        }
        
        return ans ;
    }
};