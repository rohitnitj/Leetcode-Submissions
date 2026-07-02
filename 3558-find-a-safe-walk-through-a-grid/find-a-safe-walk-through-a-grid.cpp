class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size() ;
        int m = grid[0].size() ;     

        vector<pair<int, int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0} } ;        

        queue<vector<int>> q ;
        q.push({0,0,health-grid[0][0]}) ;

        vector<vector<int>> visited(n, vector<int>(m,-1) ) ;
        visited[0][0] = health - grid[0][0];

        while( !q.empty() ) {
            vector<int> front = q.front() ;
            q.pop() ;

            int x = front[0] ;
            int y = front[1] ;
            int h = front[2] ;

            if( x == n-1 && y == m-1 && h >= 1 ) return true ;

            for( int i = 0 ; i < 4 ; i++ ) {
                int nx = x + directions[i].first ;
                int ny = y + directions[i].second ;

                if( nx >= 0 && nx < n && ny >= 0 && ny < m ){
                    int new_health = h - grid[nx][ny] ;
                    
                    if( new_health > 0 && new_health > visited[nx][ny] ) {
                        visited[nx][ny] = new_health ;
                        q.push({nx, ny, new_health}) ;
                    }
                }
            }
        }

        return false ;
    }
};