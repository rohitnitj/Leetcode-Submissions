typedef long long ll ;
class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        ll l = 0, u = 0, d = 0 ;

        for( auto a : differences ) {
            d += a ;
            l = min(l, d ) ;
            u = max(u, d ) ;
        }

        ll d1 = upper - lower ;
        ll d2 = u - l ;

        return ( d1 - d2 < 0 ) ? 0 : ( d1 - d2 + 1 ) ;
    }
};