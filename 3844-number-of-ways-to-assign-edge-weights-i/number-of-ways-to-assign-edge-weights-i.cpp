typedef long long ll ; 
const int MOD = 1e9 + 7 ; 

class Solution {
public:
    ll expo( ll base, ll power ) {
        ll ans = 1 ; 
        while( power ) {
            if( power & 1) ans = ans * base % MOD ; 
            base = base * base % MOD ; 
            power /= 2 ; 
        }
        return ans ; 
    }

    ll findInverse( int r ) {
        return expo( r, MOD-2 ) ; 
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() ; 

        vector<vector<int>> adj(n+2) ; 
        for( auto it : edges ) {
            int u = it[0], v = it[1] ; 
            adj[u].push_back(v) ; 
            adj[v].push_back(u) ; 
        }

        // {depth, node, parent } 
        queue<vector<int>> q ; 
        q.push({0, 1, 0} ) ; 

        int maxDepth = 0 ; 

        while( !q.empty() ) {
            auto it = q.front() ; 
            q.pop() ; 

            int depth = it[0], node = it[1], parent = it[2] ; 
            maxDepth = max( maxDepth, depth ) ; 

            for( auto &child : adj[node] ) {
                if( child == parent ) continue ; 
                q.push( { depth+1, child, node } ) ; 
            }
        }

        ll ans = 0 ; 
        ll ncr = 1 ; 
        for( ll r = 1 ; r <= maxDepth ; r++ ) {
            ncr =( ncr * ( maxDepth - r + 1 )) % MOD ; 
            ncr = ncr * findInverse(r) % MOD ;
            if( r & 1 ) ans = ( ans + ncr ) % MOD ; 
        }

        return ans ; 
    }
};