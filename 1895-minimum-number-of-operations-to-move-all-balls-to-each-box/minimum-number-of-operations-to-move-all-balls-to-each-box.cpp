// TC : O(n ) 
// SC : O(n ) 

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size() ;
        vector<int> ans(n ) ;

        int left_balls = 0 , moves_left = 0 ;
        int right_balls = 0, moves_right = 0 ;

        for( int i = 0 ; i < n ; i++ ) {
            
            ans[i] += moves_left ;
            left_balls += boxes[i] - '0' ;
            moves_left += left_balls ;

            int j = n - i - 1 ;
            ans[j] += moves_right ;
            right_balls += boxes[j] - '0' ;
            moves_right += right_balls ;
        }

        return ans ; 
    }
};