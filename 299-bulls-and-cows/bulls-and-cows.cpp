class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size() ;
        vector<int> A(10), B(10 ) ;

        int b = 0, c = 0 ;
        for( int i = 0 ; i < n ; i++ ) {
            if( secret[i] == guess[i] ) b++ ;
            else {
                A[secret[i] - '0' ]++ ;
                B[guess[i] - '0']++ ;
            }
        }
        
        for( int i = 0 ; i < 10 ; i++ ) {
            c += min( A[i], B[i] ) ;
        }

        string ans = to_string(b) + "A" + to_string(c) + "B" ;
        return ans ;
    }
};