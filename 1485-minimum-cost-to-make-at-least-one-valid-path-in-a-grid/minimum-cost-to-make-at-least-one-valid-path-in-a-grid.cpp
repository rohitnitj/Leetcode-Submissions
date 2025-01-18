class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size() ;

        vector<vector<int>> cost(n, vector<int> (m, INT_MAX ) ) ;
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>> > pq ;

        pq.push({0, {0, 0 } } ) ;
        cost[0][0] = 0 ;

        while(!pq.empty()) {
            auto it = pq.top() ; 
            pq.pop() ;

            int curr_cost = it.first ;
            int x = it.second.first ;
            int y = it.second.second ;

            vector<int> dx = {0, 0, 1, -1 } ;
            vector<int> dy = {1, -1, 0, 0 } ;
            
            for( int i = 0 ; i < 4 ; i++ ) {
                int nx = x + dx[i] ;
                int ny = y + dy[i] ;

                if( nx < 0 || nx >= n || ny < 0 || ny >= m ) continue; 
                int next_cost = curr_cost + ( i != grid[x][y] - 1 ) ;

                if( next_cost < cost[nx][ny] ) {
                    cost[nx][ny] = next_cost ;
                    pq.push( {next_cost, {nx, ny } } ) ;
                }
            }
        }

        return cost[n-1][m-1] ;
    }   
};