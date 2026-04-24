class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int mini = 0, maxi = 0 ; 

        for( char ch : moves ) {
            if( ch == 'L' ) {
                mini-- ; 
                maxi-- ; 
            }
            else if( ch == 'R' ) {
                mini++ ; 
                maxi++ ; 
            }
            else{
                mini-- ; 
                maxi++ ; 
            }
        }

        return max( abs(mini), abs( maxi ) ) ; 
    }
};