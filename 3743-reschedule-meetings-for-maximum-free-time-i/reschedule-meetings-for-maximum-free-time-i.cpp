class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size() ;
        vector<int> gap(n+1, 0) ;

        gap[0] = startTime[0] ;
        gap[n] = eventTime - endTime[n-1] ;

        for(int i = 1 ; i < n ; i++ ) {
            gap[i] = startTime[i] - endTime[i-1] ;
        }

        int window = 0 ;
        for( int i = 0 ; i <= k ; i++ ) {
            window += gap[i] ;
        }

        int ans = window ;
        for( int i = k+1 ; i <= n ; i++ ) {
            window += gap[i] ;
            window -= gap[i-(k+1)] ;
            ans = max(ans, window ) ;
        }

        return ans ;
    }
};