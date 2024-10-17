class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num) ;
        int n = s.size() ;
        vector<int> maxIndArr(n) ;

        int maxIndex = n-1 ;
        maxIndArr[maxIndex] = maxIndex ;

        for( int i = n-2 ; i >= 0 ; i-- ) {
            if( s[i] > s[maxIndex] ) maxIndex= i ;
            maxIndArr[i] = maxIndex ;
        }

        for( int i = 0 ; i < n; i++ ) {
            if( s[i] < s[maxIndArr[i]] ) {
                swap( s[i], s[maxIndArr[i]] ) ;
                break ;
            }
        }
        
        return stoi(s) ;
    }
};