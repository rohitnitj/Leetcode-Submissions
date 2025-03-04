class Solution {
private:
    bool func(int idx, int ans, int n) {
        if( ans == n ) return true ;
        if( pow(3, idx ) > n ) return false ;
        return func(idx+1, ans + pow(3, idx), n ) || func(idx+1, ans, n ) ;
    }

public:
    bool checkPowersOfThree(int n) {
        return func(0, 0, n) ;
    }
};