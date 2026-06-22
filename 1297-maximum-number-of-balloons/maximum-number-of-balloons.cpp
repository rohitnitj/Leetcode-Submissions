class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char, int> mpp ; 
        for( char ch : text ) mpp[ch]++ ; 

        int ans = mpp['b'] ; 
        ans = min( ans, mpp['a'] ) ;
        ans = min( ans, mpp['l'] / 2 ) ; 
        ans = min( ans, mpp['o'] / 2  ) ; 
        ans = min( ans, mpp['n'] ) ; 

        return ans ; 
    }
};