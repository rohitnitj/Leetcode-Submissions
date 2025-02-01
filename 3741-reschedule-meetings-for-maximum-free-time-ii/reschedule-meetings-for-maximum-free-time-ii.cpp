class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size() ;

        vector<int> meet_time(n ) ;
        for( int i = 0 ; i < n ; i++ ) {
            meet_time[i] = endTime[i] - startTime[i] ;
        }

        vector<int> free_slot ;
        free_slot.push_back(startTime[0] ) ;
        for( int i = 1 ; i < n ;i++ ) {
            free_slot.push_back( startTime[i] - endTime[i-1] ) ;
        }
        free_slot.push_back( eventTime - endTime[n-1] ) ;

        int max_free_time = 0 ;
        for( int i = 1 ; i < n+1 ; i++ ) {
            max_free_time = max( max_free_time, free_slot[i-1] + free_slot[i] ) ;
        }

        vector<int> pre = free_slot ;
        vector<int> post = free_slot ;

        for( int i = 1 ; i < n+1 ; i++ ) {
            pre[i] = max(pre[i-1], pre[i] ) ;
        }

        for( int j = n-1 ; j >= 0 ; j-- ) {
            post[j] = max( post[j], post[j+1] ) ;
        }

        auto check = [&]( int i ) {
            if( i > 0 && pre[i-1] >= meet_time[i] ) {
                return true ;
            }
            if( i < n-1 && post[i+2] >= meet_time[i] ) {
                return true ;
            }
            return false ;
        } ;

        for( int i = 0 ; i < n ; i++ ) {
            if( check(i ) ) {
                max_free_time = max( max_free_time, free_slot[i] + meet_time[i] + free_slot[i+1] ) ;
            }
        }

        return max_free_time ;
    }
};