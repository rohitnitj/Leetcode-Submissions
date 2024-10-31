// Space Optimization
// TC : O( M * N^2 ) 
// SC : O( m + S ) 

class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        
        sort( robot.begin(), robot.end() ) ;
        sort( factory.begin(), factory.end() ) ;

        vector<int> factPos ;
        for( int i = 0 ; i < factory.size() ; i++ ) {
            for( int j = 0 ; j < factory[i][1] ; j++ ) {
                factPos.push_back(factory[i][0] ) ;
            }
        }

        int rs = robot.size() ;
        int fs = factPos.size() ;
        vector<long long> next(fs+1, 0 ) ;
        vector<long long> curr(fs+1, 0 ) ;

        for( int i = rs-1 ; i >= 0 ; i-- ) {
            if( i != rs-1 ) next[fs] = 1e18 ;
            curr[fs] = 1e18 ;

            for( int j = fs-1 ; j >= 0 ; j-- ) {

                long long assign = abs( robot[i] - factPos[j] ) + next[j+1] ;
                long long skip = curr[j+1] ;

                curr[j] = min( assign, skip ) ;
            }

            next = curr ;
        }

        return curr[0] ;
    }
};