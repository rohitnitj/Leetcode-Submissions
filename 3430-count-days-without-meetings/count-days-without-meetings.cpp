class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int cnt = 0 ;
        sort(meetings.begin(), meetings.end()) ;

        int l = 0 ;
        for( auto m : meetings ) {
            int s = m[0], e = m[1] ;
            if( s > l+1 ) cnt += ( s - l - 1 ) ;
            l = max(e, l ) ;
        }
        
        if( days > l ) cnt += days - l ; 
        return cnt ; 
    }
};