class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int n = grid.size() ;
        int m = grid[0].size() ;

        int t = x, b = x + k - 1 ;
        int l = y, r = y + k - 1 ;

        while( t < b ) {
            for( int i = l ; i <= r ; i++ ) {
                swap(grid[t][i], grid[b][i] ) ;
            }
            t++ ;
            b-- ;
        }

        return grid ;
    }
};
