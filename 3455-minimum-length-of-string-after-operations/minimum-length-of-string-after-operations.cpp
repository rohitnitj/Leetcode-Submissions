class Solution {
public:
    int minimumLength(string s) {
        int n = s.size() ;
        vector<int> mpp(26, 0 ) ;

        for( auto ch : s ) {
            mpp[ch-'a']++ ;
        }

        int ans = 0 ;
        for( int i = 0 ; i < 26 ; i++ ) {
            if( mpp[i] <= 2 ) {
                ans += mpp[i] ;
            }
            else if(mpp[i] & 1 ) {
                ans++ ;
            }
            else {
                ans += 2;
            }
        }

        return ans ;
    }
};