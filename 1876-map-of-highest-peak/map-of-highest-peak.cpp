class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size() ;
        int m = isWater[0].size() ;

        vector<vector<int>> ans(n, vector<int>(m, 0 ) ) ;
        vector<vector<int>> vis(n, vector<int>(m, 0 ) ) ;
        queue<pair<int, pair<int,int>>> q ;

        for( int i = 0 ; i < n ; i++ ) {
            for(int j = 0 ; j < m ; j++ ) {
                if( isWater[i][j] == 1 ) {
                    vis[i][j] = 1 ;
                    q.push( {0, {i, j } } ) ;
                }
            }
        }

        vector<int> dx = {-1, 0, 1, 0 } ;
        vector<int> dy = {0, -1, 0, 1 } ;

        while( !q.empty() ) {
            auto it = q.front() ;
            q.pop() ;

            int value = it.first ;
            int x = it.second.first ;
            int y = it.second.second ;

            for( int i = 0 ; i < 4 ; i++ ) {
                int nx = x + dx[i] ;
                int ny = y + dy[i] ;

                if( nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] ){
                    ans[nx][ny] = value+1 ;
                    q.push({value+1, {nx, ny } } ) ;
                    vis[nx][ny] = 1 ;
                }
            }
        }

        return ans ;
    }
};