class Solution {
private:
    bool isSafe(vector<string> &arr, int row, int col, int n ) {

        for( int i = 0 ; i < col ; i++ ) {
            if( arr[row][i] == 'Q' ) return false ;
        }

        for( int i = 0 ; i < row ; i++ ) {
            if( arr[i][col] == 'Q' ) return false ;
        }

        for( int i = row, j = col ; i >= 0 && j >= 0 ; i-- , j-- ) {
            if( arr[i][j] == 'Q' ) return false ;
        }

        for( int i = row, j = col ; j < n && i >= 0 ; i--, j++ ) {
            if( arr[i][j] == 'Q' ) return false ;
        }

        return true ;
    }

    void func(vector<vector<string>> &ans, vector<string> &arr, int row, int n ) {
        if( row == n ) {
            ans.push_back(arr ) ;
            return ;
        }

        for(int i = 0 ; i < n ; i++ ) {

            if( isSafe(arr, row, i, n ) ) {
                arr[row][i] = 'Q' ;
                func(ans, arr, row+1, n ) ;
                arr[row][i] = '.' ;
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans ;
        vector<string> arr(n, string(n, '.' ) ) ;

        func(ans, arr, 0, n ) ;
        return ans ;
    }
};
