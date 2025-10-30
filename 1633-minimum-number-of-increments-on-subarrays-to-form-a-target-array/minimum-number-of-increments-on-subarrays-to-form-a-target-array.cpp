class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int ans = 0, curr = 0 ;

        for( int a : target ) {
            if( a > curr ) {
                int diff = a - curr ;
                ans += diff ;
                curr += diff ;
            }
            curr = min(curr, a ) ;
        }

        return ans ; 
    }
};