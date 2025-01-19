class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size() ;
        int m = heightMap[0].size() ;
        
        vector<vector<int>> vis(n, vector<int>(m, 0 ) ) ;
        priority_queue< pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq ;

        for( int i = 0 ; i < n ; i++ ) {
            pq.push( {heightMap[i][0], {i, 0 } } ) ;
            pq.push( {heightMap[i][m-1], {i, m-1 } } ) ;
            vis[i][0] = vis[i][m-1] = 1 ;
        }

        for( int j = 0 ; j < m ; j++ ) {
            pq.push( {heightMap[0][j], {0, j } } ) ;
            pq.push( {heightMap[n-1][j], {n-1, j } } ) ;
            vis[0][j] = vis[n-1][j] = 1 ;
        }

        vector<int> dr = {-1, 0, 1, 0 } ;
        vector<int> dc = {0, -1, 0, 1 } ;
        int water = 0 ;

        while( !pq.empty() ) {
            auto it = pq.top() ;
            pq.pop() ;

            int height = it.first ;
            int r = it.second.first ;
            int c = it.second.second ;

            for( int i = 0 ; i < 4 ; i++ ) {
                int nr = r + dr[i] ;
                int nc = c + dc[i] ;

                if( nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] ) {
                    vis[nr][nc] = 1 ;
                    int new_height = heightMap[nr][nc] ;

                    if( new_height < height ) {
                        water += ( height - new_height ) ;
                    }                    

                    pq.push( {max(height, new_height), {nr, nc } } ) ;
                }
            }
        }

        return water ;
    }
};