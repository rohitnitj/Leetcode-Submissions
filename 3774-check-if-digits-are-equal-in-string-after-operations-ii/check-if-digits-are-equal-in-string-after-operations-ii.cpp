class Solution {
private:    
    int nCkMod10(int n, int k ) {
        int mod2 = nCkLucaMod2(n, k ) ;
        int mod5 = nCkLucaMod5(n, k ) ;
        for( int i = 0 ; i < 10 ; i++ ) {
            if( i % 2 == mod2 && i % 5 == mod5 ) {
                return i ;
            }
        }
        return 0 ;
    }

    int nCkLucaMod2(int n, int k ) {
        int ans = 1 ;
        while( n > 0 || k > 0 ) {
            int nd = n % 2 ;
            int kd = k % 2 ;
            if( kd > nd ) return 0 ;
            ans = ( ans * nCkMod2(nd, kd ) ) % 2 ;
            n /= 2 ;
            k /= 2 ;
        }
        return ans ;
    }

    int nCkMod2(int n, int k ) {
        if( k > n ) return 0 ;
        return 1 ;
    }

    int nCkLucaMod5(int n, int k ) {
        int ans = 1 ;
        while( n > 0 || k > 0 ) {
            int nd = n % 5 ;
            int kd = k % 5 ;
            if( kd > nd ) return 0 ;
            ans = ( ans * nCkMod5(nd, kd ) ) % 5 ;
            n /= 5 ; 
            k /= 5 ;
        }
        return ans ;
    }

    int nCkMod5(int n, int k ) {
        if( k > n ) return 0 ;
        int factMod5[5] = {1, 1, 2, 1, 4} ;
        int num = factMod5[n] ;
        int den = ( factMod5[k] * factMod5[n-k] ) % 5 ;
        int denInv = 0 ;
        for( int i = 0 ; i < 5 ; i++ ) {
            if( ( den * i ) % 5 == 1 ) {
                denInv = i ;
                break; 
            }
        }
        return (num * denInv) % 5 ;
    }

public:
    bool hasSameDigits(string s) {
        int length = s.size() ;
        int n = length - 2 ;
        int x  = 0, y = 0 ;

        for( int i = 0 ; i <= n ; i++ ) {
            int c = nCkMod10(n, i ) ;
            int a = s[i] - '0' ;
            int b = s[i+1] - '0' ;  

            x = ( x + c*a ) % 10 ;
            y = ( y + c*b ) % 10 ;
        }

        return ( x == y ) ;
    }
};