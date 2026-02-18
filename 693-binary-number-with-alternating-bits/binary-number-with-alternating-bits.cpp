class Solution {
public:
    bool hasAlternatingBits(int n) {

        int prev = n % 2 ;
        n /= 2 ;
        int curr = 0 ;        

        while( n) {
            curr = n % 2 ;
            if( curr == prev ) return false ; 

            prev = curr ;
            n /= 2 ;
        }

        return true ;
    }
};