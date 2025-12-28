class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int cnt = 0 ;
        
        for( auto &aa : grid ) {
            for( int a : aa ) {
                cnt += ( a < 0 ) ;
            }
        }

        return cnt ;
    }
};