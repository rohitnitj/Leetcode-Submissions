class Solution {
public:
    bool check(vector<vector<int>> &arr, int r, int c ) {
        for( int i = 0 ; i < arr.size() ; i++ ) if( arr[r][i] != arr[i][c] ) return false ;
        return true ;
    }

    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size() ;

        int cnt = 0 ;
        for( int i = 0 ; i < n ; i++ ) {
            for( int j = 0 ; j < n ; j++ ) {
                if( check(grid, i, j ) ) cnt++ ;
            }
        }      

        return cnt ;
    }
};
