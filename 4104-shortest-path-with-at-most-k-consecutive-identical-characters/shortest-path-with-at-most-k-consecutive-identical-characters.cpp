class Solution{
public : 
    int shortestPath( int n, vector<vector<int>> &edges, string labels, int k ) {
        vector<vector<pair<int, int>>> adj(n) ; 
        for( auto &edge : edges ) {
            adj[edge[0]].push_back( { edge[1], edge[2] } ) ; 
        }

        vector<vector<int>> dist(n, vector<int>(k+1, INT_MAX) ) ; 
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int,3>>> pq ; 

        dist[0][1] = 0 ; 
        pq.push( { 0, 0, 1 } ) ; 

        while( !pq.empty() ) {
            auto [d, node, count ] = pq.top() ; 
            pq.pop() ; 

            if( node == n-1 ) return d ; 
            if( d > dist[node][count] ) continue ; 

            for( auto &[child, wt] : adj[node] ) {
                int nextCount = ( labels[node] == labels[child] ) ? count + 1 : 1 ; 

                if( nextCount <= k ) {
                    if( d + wt < dist[child][nextCount] ) {
                        dist[child][nextCount] = d + wt ; 
                        pq.push( { d + wt, child, nextCount } ) ; 
                    }
                }
            }
        }
        
        return -1;
    }
};