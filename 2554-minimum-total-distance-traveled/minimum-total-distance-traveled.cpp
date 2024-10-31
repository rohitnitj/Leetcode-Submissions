// Memorization
// TC : O( N^2 * M ) 
// SC : O( N * M ) 

class Solution {
long long func( int ri, int fi, vector<int> &robot, vector<int> &factpos, vector<vector<long long>> &dp) {

   if( ri == robot.size() ) return 0 ;
   if( fi == factpos.size() ) return 1e18 ;
   if( dp[ri][fi] != -1 ) return dp[ri][fi] ;

   long long assign = abs( robot[ri] - factpos[fi] ) + func( ri+1, fi+1, robot, factpos, dp) ;
   long long skip = func( ri, fi+1, robot, factpos, dp ) ;

   return dp[ri][fi] = min( assign, skip ) ; 
}

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
        vector<vector<long long>> dp(rs, vector<long long> (fs, -1 ) ) ;

        return func(0, 0, robot, factPos, dp) ;
    }
};