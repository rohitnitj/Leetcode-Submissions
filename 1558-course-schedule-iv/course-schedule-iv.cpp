class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int n = numCourses ;
        vector<vector<bool>> reachable(n, vector<bool>(n, false ) ) ;

        for( auto &p : prerequisites ) {
            reachable[p[0]][p[1]] = true ;
        }

        for( int k = 0 ; k < n ; k++ ) {
            for( int i = 0 ; i < n ; i++ ) {
                for( int j = 0 ; j < n ; j++ ) {
                    if( reachable[i][k] && reachable[k][j] ) {
                        reachable[i][j] = true ;
                    }
                }
            }
        }

        vector<bool> ans ;
        for( auto q : queries ) {
            ans.push_back(reachable[q[0]][q[1]] );
        }

        return ans ;
    }
};