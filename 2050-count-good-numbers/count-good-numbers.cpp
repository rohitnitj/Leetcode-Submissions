class Solution {
    long long mod = 1e9 + 7 ;

private:
    long long pow(long long x, long long y ) {
        long long ans = 1 ;
        x = x % mod ;
        if( x == 0 ) return 0 ;

        while( y > 0 ) {
            if( y & 1 ) ans = (ans * x ) % mod ;
            y >>= 1 ;
            x = (x%mod * x%mod ) % mod ;            
        }

        return ans ;
    }

    long long func(long long n ) {
        if( n == 1 ) return 5 ;
        if( n == 2 ) return 20 ;
        if( n & 1 ) return( 5 * func(n-1 )%mod)%mod ;
        return pow(20, n/2 ) ;
    }
public:
    int countGoodNumbers(long long n) {
        return func(n) % mod ;
    }
};