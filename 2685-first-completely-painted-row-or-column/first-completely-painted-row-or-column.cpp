class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int row = mat.size() ;
        int col = mat[0].size() ;

        vector<pair<int,int>> mpp(row*col+1 );
        for( int i = 0 ; i < row ; i++ ) {
            for( int j = 0 ; j < col ; j++ ) {
                mpp[mat[i][j]] = {i, j } ;
            }
        }

        vector<int> row_freq(row, 0 ) ;
        vector<int> col_freq(col, 0 ) ;

        for( int ind = 0 ; ind < arr.size() ; ind++ ) {
            auto it = mpp[arr[ind]];
            int i = it.first ;
            int j = it.second ;

            row_freq[i]++ ;
            if( row_freq[i] == col ) return ind ;

            col_freq[j]++ ;
            if( col_freq[j] == row ) return ind ;
        }
        
        return -1 ;
    }
};