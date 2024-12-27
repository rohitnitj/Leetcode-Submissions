class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size() ;

        vector<int> max_left_score(n ) ;
        max_left_score[0] = values[0] ;
        int max_score = 0 ;

        for( int i = 1 ; i < n ; i++ ) {
            int curr_right_score = values[i] - i ;

            int curr_score = max_left_score[i-1] + curr_right_score ;
            max_score = max(max_score, curr_score ) ;

            int curr_left_score = values[i] + i ;
            max_left_score[i] = max(max_left_score[i-1], curr_left_score ) ;
        }        

        return max_score ;
    }
};