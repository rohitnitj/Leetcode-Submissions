class Solution {
public:
    int largestInteger(int num) {
        string s = to_string(num) ;
        int n = s.size() ;
        
        string mpp(n,'c') ;
        for( int i = 0 ; i < n ; i++ ) {
            int d = s[i] - '0' ;
            if( d & 1 ) mpp[i] = 'o' ;
            else mpp[i] = 'e' ;
        }

        sort(s.begin(), s.end() ) ;
        reverse(s.begin(), s.end() ) ;

        int i = 0 , j = 0 ;
        for( int k = 0 ; k < n ; k++ ) {
            int d = s[k] - '0' ;

            if( d & 1 ) {
                while( mpp[i] != 'o' ) i++ ;
                mpp[i] = s[k] ;
            }
            else{
                while( mpp[j] != 'e' ) j++ ;
                mpp[j] = s[k] ;
            }
        }

        return stoi(mpp) ;
    }
};