class Solution {
public:
    int maximum69Number (int num) {
        vector<int> A ;
        while( num ) {
            A.push_back( num % 10 ) ;
            num /= 10 ;
        }
        
        reverse(A.begin(), A.end() ) ;
        for( int &a : A ) {
            if( a == 6 ) {
                a = 9 ;
                break ;
            }
        }

        for( int a : A ) num = num * 10 + a ;
        return num ;
    }
};