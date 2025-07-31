class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int sum = accumulate(colsum.begin(), colsum.end(), 0 ) ;
        if( sum != upper + lower ) return {} ;

        int n = colsum.size() ;
        vector<vector<int>> ans(2, vector<int> (n, 0)) ;

        for( int i = 0 ; i < n ; i++ ) {
            if( colsum[i] == 2 ) {
                if( !upper || !lower ) return {} ;
                ans[0][i] = 1 ;
                ans[1][i] = 1 ;
                upper-- ;
                lower-- ;
            }
        }

        for( int i = 0 ; i < n ; i++ ) {
            if( colsum[i] == 1 ) {
                if( upper ) {
                    ans[0][i] = 1 ;
                    upper-- ;
                }
                else{
                    ans[1][i] = 1 ;
                    lower-- ;
                }
            }
        }

        return ans ;
    }
};