class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> freq(26) ;
        for( char ch : s ) freq[ch - 'a' ]++ ;

        int v = 0, c = 0 ;
        for( int i = 0 ; i < 26 ; i++ ) {
            char ch = i + 'a' ;
            if( ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ) v = max(v, freq[i] ) ;
            else c = max(c, freq[i] ) ;
        }

        return v + c ; 
    }
};