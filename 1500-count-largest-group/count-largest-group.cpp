class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int,int> mpp;
        
        for( int i = 1 ; i <= n ; i++ ) {
            int digit = i, dsum = 0 ;
            while( digit ) {
                dsum += ( digit % 10 ) ;
                digit /= 10 ;
            }
            mpp[dsum]++ ;
        }
        
        int ans = 0, maxi = 0 ;
        for( auto it : mpp ) {
            int val = it.second ;

            if( val > maxi ) {
                ans = 1;
                maxi = val ;
            }
            else if( val == maxi ) ans++ ;
        }

        return ans ;
    }
};
