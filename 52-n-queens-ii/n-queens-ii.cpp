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

    void func(int &cnt, vector<string> &arr, int row, int n ) {
        if( row == n ) {
            cnt++ ;
            return ;
        }

        for(int i = 0 ; i < n ; i++ ) {

            if( isSafe(arr, row, i, n ) ) {
                arr[row][i] = 'Q' ;
                func(cnt , arr, row+1, n ) ;
                arr[row][i] = '.' ;
            }
        }
    }

public:
    int totalNQueens(int n) {
        int ans = 0 ;
        vector<string> arr(n, string(n, '.' ) ) ;

        func(ans, arr, 0, n ) ;
        return ans ;
    }
};