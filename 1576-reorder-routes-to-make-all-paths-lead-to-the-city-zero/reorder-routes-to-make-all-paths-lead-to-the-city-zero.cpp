class Solution {
public:
    int cnt = 0 ;
    
    void dfs( int node, int parent,  vector<vector<pair<int,int>>> &adj ) {
        for( auto &[nbr, sign] : adj[node] ) {
            if( nbr != parent ) {
                cnt += sign ;
                dfs(nbr, node, adj ) ;
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n ) ;
        for( auto &c : connections ) {
            adj[c[0]].push_back( { c[1], 1 } ) ;
            adj[c[1]].push_back( { c[0], 0 } ) ;
        }
        dfs(0, -1, adj ) ;
        return cnt ;
    }
};