class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> maxReach(n+1, 0 ) ;
        
        for( int i = 0 ; i <= n ; i++ ) {
            int l = max(0, i - ranges[i] ) ;
            int r = min(n, i + ranges[i] ) ;
            maxReach[l] = max(maxReach[l], r ) ;
        }

        int cnt = 0, curr = 0, far = 0;
        for( int i = 0 ; i <= n ; i++ ) {
            if( i > far ) return -1 ;
            if( i > curr ) {
                cnt++ ;
                curr = far ;
            }
            far = max(far, maxReach[i] ) ;
        }

        return cnt ;
    }
};