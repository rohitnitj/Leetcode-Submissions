class Solution {
public:
    int kthGrammar(int n, int k) {
        if( n == 1 ) return 0 ;

        if( k & 1 ) {
            int prev = kthGrammar( n - 1, ( k / 2 ) + 1 ) ;
            return prev ;
        }
        else{
            int prev = kthGrammar( n - 1, k / 2 ) ;
            return 1 - prev ;
        }
    }
};