class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<int> ans;
        ans.reserve(n * m);

        int i = 0, j = 0;
        bool up = true;

        while (ans.size() < n * m) {
            ans.push_back(mat[i][j]);

            if (up) {
                // Going up
                if (j == m - 1) { // right boundary
                    i++;
                    up = false;
                } else if (i == 0) { // top boundary
                    j++;
                    up = false;
                } else { // move up-right
                    i--;
                    j++;
                }
            } else {class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size() ;
        int m = mat[0].size() ;

        vector<int> ans ;
        int i = 0, j = 0 ;
        bool up = true ;

        while( ans.size() < n * m ) {
            ans.push_back( mat[i][j] ) ;

            if( up ) {
                if( i == 0 ) {
                    j++ ;
                    up = false ;
                }
                else if( j == m-1 ) {
                    i-- ;
                    up = false ;
                }
                else{
                    i-- ;
                    j++ ;
                }
            }
            else{
                if( j == 0 ) {
                    i++ ;
                    up = true ;
                }
                else if( i == n-1 ) {
                    j++ ;
                    up = true ;
                }
                else{
                    i++ ;
                    j-- ;
                }
            }
        }

        return ans ;
    }
};

                // Going down
                if (i == n - 1) { // bottom boundary
                    j++;
                    up = true;
                } else if (j == 0) { // left boundary
                    i++;
                    up = true;
                } else { // move down-left
                    i++;
                    j--;
                }
            }
        }

        return ans;
    }
};
