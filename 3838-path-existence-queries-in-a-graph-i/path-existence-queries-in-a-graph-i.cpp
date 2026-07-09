class Solution {
public:
    int findUltimateParent( int node, vector<int> &parent ) {
        if( parent[node] == node ) return node ; 
        return parent[node] = findUltimateParent( parent[node], parent ) ; 
    }

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {

        vector<int> parent(n) ;
        for( int i = 0 ; i < n; i++ ) parent[i] = i ; 

        int l = 0, r = 0 ; 
        for( r = 0 ; r < n ; r++ ) {
            while( nums[r] - nums[l] > maxDiff ) l++ ; 
            int u = findUltimateParent(l, parent ) ;
            int v = findUltimateParent(r, parent ) ;
            if( u != v ) {
                parent[v] = u ; 
            } 
        }

        vector<bool> ans ; 
        for( auto q : queries ) {
            int u = q[0], v = q[1] ; 
            if( parent[u] == parent[v] ) ans.push_back( true ) ; 
            else ans.push_back( false) ; 
        }

        return ans ; 
    }
};