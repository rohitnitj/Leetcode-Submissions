class Solution {
public:
    int minDeletions(string s) {
        vector<int> F(26, 0) ;
        for( char ch : s ) {
            F[ch - 'a' ]++ ;
        }

        priority_queue<int> pq ;
        for( int f : F ) {
            if( f ) pq.push(f) ;
        }

        int cnt = 0 ;
        set<int> st ;
        
        while( !pq.empty() ) {
            int x = pq.top() ;
            pq.pop() ;

            while( st.find(x) != st.end() ) {
                if( x == 0 ) break ;
                cnt++ ;
                x-- ;
            }

            st.insert(x) ;
        }

        return cnt ;
    }
};