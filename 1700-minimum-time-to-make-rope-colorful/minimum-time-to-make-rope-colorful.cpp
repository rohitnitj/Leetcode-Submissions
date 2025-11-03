class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size() ;

        priority_queue<int, vector<int>, greater<int> > pq ;
        pq.push( neededTime[0] ) ;

        int ans = 0 ;
        for( int i = 1 ; i < n ; i++ ) {
            if( colors[i] != colors[i-1] ) {
                while( pq.size() > 1 ) {
                    ans += pq.top() ;
                    pq.pop() ;
                }
                pq.pop();
            }
            pq.push( neededTime[i] ) ;
        }

        while( pq.size() > 1 ) {
            ans += pq.top() ;
            pq.pop() ;
        }

        return ans ;
    }
};