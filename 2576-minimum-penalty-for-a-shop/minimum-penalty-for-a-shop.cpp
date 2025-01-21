class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size() ;
        int lsum = 0, rsum = 0 ;

        for( int i = 0 ; i < n ; i++ ) {
            if( customers[i] == 'N' ) lsum++ ;
        }

        int min_penality = lsum, ans = n;

        for( int i = n-1 ; i >= 0 ; i-- ) {
            if( customers[i] == 'Y' ) rsum++ ;
            if( customers[i] == 'N' ) lsum-- ;
            int penality = lsum + rsum ;
            if( penality <= min_penality ) {
                min_penality = penality ;
                ans = i ;
            }
        }

        return ans ;
    }
};