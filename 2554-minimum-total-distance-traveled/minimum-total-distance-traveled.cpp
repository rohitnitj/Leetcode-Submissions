// Tabulation
// TC : O( M * N^2 ) 
// SC : O( N * M ) 

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
        vector<vector<long long>> dp(rs+1, vector<long long> (fs+1, 0 ) ) ;

        for( int i = 0 ; i < rs ; i++ ) dp[i][fs] = 1e18 ;
        for( int j = 0 ; j < fs ; j++ ) dp[rs][j] = 0 ;

        for( int i = rs- 1 ; i >= 0 ; i-- ) {
            for(int j = fs - 1; j >= 0 ; j-- ) {

                long long assign = abs( robot[i] - factPos[j] ) + dp[i+1][j+1] ;
                long long skip = dp[i][j+1] ;
                dp[i][j] = min(assign, skip ) ;
            }
        }

        return dp[0][0] ;
    }
};