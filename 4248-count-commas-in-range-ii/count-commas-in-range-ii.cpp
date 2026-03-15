typedef long long ll ; 

class Solution {
public:
    long long countCommas(long long n) {
        ll ans = 0 ; 

        for( int i = 4 ; i <= 18 ; i++ ) {
            ll curr = ( i - 1 ) / 3  ;
            if( i == 0 ) continue ; 

            ll l = 1 ; 
            for( int j = 1 ; j < i ; j++ ) l *= 10 ; 

            ll r = l * 10 - 1 ; 

            if( l > n ) break ; 

            ll cnt = min(r, n ) - l + 1 ; 
            ans += cnt * curr ;
        }

        return ans; 
        
    }
};