class Solution {
public:
    std::vector<int> remainingMethods(int n, int k, std::vector<std::vector<int>>& invocations) {
        
        vector<vector<int>> adj(n) ; 
        for( const auto &inv : invocations ) {
            adj[inv[0]].push_back(inv[1]) ; 
        }

        vector<bool> suspicious(n, false ) ; 
        queue<int> q ; 

        q.push(k) ; 
        suspicious[k] = true ; 

        while( !q.empty() ) {
            int curr = q.front() ; 
            q.pop() ; 

            for( int neighbor : adj[curr] ) {
                if( !suspicious[neighbor] ) {
                    suspicious[neighbor] = true ; 
                    q.push( neighbor ) ; 
                }
            }
        }

        bool canRemove = true ; 
        for( const auto &inv : invocations ) {
            int u = inv[0] ; 
            int v = inv[1] ; 
            if( !suspicious[u] && suspicious[v] ) {
                canRemove = false ; 
                break ; 
            }
        }

        vector<int> ans ; 
        if( canRemove ) {
            for( int i = 0 ; i < n; i++ ) {
                if( !suspicious[i] ) {
                    ans.push_back(i) ; 
                }
            }
        }
        else {
            for( int i = 0 ; i < n ; i++ ) {
                ans.push_back(i) ; 
            }
        }

        return ans ; 
    }
};