class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int,int>>> adj(n+1 ) ;
        for( auto it : times ) {
            adj[it[0]].push_back( {it[1], it[2] } ) ;
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq ;
        vector<int> dist(n+1, 1e9 ) ;
        pq.push({0, k } ) ;
        dist[k] = 0 ;

        while( !pq.empty() ) {
            auto it = pq.top() ;
            pq.pop() ;

            int dis = it.first ;
            int node = it.second ;

            for( auto itr : adj[node] ) {
                int adjNode = itr.first ;
                int adjDis = itr.second ;

                if( dis + adjDis < dist[adjNode] ) {
                    dist[adjNode] = dis + adjDis ;
                    pq.push({dis+adjDis, adjNode} ) ;
                }
            }
        }
        
        int ans = 0 ;
        for( int i = 1 ; i <= n ; i++ ) {
            if( dist[i] == 1e9 ) return -1 ;
            ans = max(ans, dist[i] ) ;
        }

        return ans ;
    }
};