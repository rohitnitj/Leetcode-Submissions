class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        vector<vector<int>> adj(n ) ;
        for( auto e : edges ) {
            adj[e[0]].push_back(e[1] ) ;
            adj[e[1]].push_back(e[0] ) ;
        }

        vector<int> vis(n, 0 ) ;
        queue<int> q ;
        q.push(source ) ;
        vis[source] = 1 ;

        while( !q.empty() ) {
            int node = q.front() ;
            q.pop() ;

            if( node == destination ) return true ;

            for( auto &adjNode : adj[node] ) {
                if( !vis[adjNode] ){
                    vis[adjNode] = 1;
                    q.push(adjNode ) ;
                } 
            }
        }

        return false  ;
    }
};