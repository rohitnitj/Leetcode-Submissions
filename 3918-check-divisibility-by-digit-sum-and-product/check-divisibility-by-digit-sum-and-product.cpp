class Solution {
public:
    int digitSum( int n ) {
        int sum = 0 ; 
        while( n ) {
            sum += n % 10 ; 
            n /= 10 ; 
        }
        return sum ; 
    }

    int digitProduct( int n ) {
        int prod = 1 ; 
        while(n ) {
            prod *= ( n % 10 ) ; 
            n /= 10 ; 
        }
        return prod ; 
    }

    bool checkDivisibility(int n) {
        int d = digitSum(n) ; 
        int p = digitProduct(n) ; 
        int q = d + p ; 
        return ( n % q == 0 ) ; 
    }
};