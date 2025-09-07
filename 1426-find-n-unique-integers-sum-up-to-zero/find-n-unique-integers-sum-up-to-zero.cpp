class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans ;
        for( int i = 1 ; i <= n -1 ; i++ ) ans.push_back(i) ;
        int x = ( n * ( n - 1 ) ) / 2 ;
        ans.push_back(-x) ;
        return ans ;
    }
};