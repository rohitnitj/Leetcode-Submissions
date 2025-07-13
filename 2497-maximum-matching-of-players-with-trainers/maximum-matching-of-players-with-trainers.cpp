class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int p = players.size() ;
        int t = trainers.size() ;
        sort( players.begin(), players.end() ) ;
        sort( trainers.begin(), trainers.end() ) ;
        
        int i = 0, j = 0, cnt = 0  ;
        while( i < p && j < t ) {
            if( players[i] <= trainers[j] ) {
                cnt++ ;
                i++ ;
                j++ ;
            }
            else {
                j++ ;
            }
        }

        return cnt ;
    }
};