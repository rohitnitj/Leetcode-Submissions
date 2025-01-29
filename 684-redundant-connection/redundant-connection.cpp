class Solution {
private:
    bool isConnected(int src, int dst, vector<vector<int>> &adj, vector<int> &vis ) {
        vis[src] = 1 ;
        if( src == dst ) return true ;

        for( auto it : adj[src] ) {
            if( !vis[it] && isConnected(it, dst, adj, vis )) {
                return true ;
            }
        }
        
        return false ;      
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size() ;
        vector<vector<int>> adj(n+1 ) ;

        for( auto edge : edges ) {
            vector<int> vis(n+1, 0 ) ;
            if( isConnected(edge[0], edge[1], adj, vis )) {
                return edge ;
            }

            adj[edge[0]].push_back(edge[1]) ;
            adj[edge[1]].push_back(edge[0]) ;
        }       

    return {} ;
    }
};
