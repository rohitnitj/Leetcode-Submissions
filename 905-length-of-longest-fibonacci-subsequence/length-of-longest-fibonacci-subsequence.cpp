class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size() ;

        unordered_set<int> st ;
        for( int a : arr ) st.insert(a ) ;

        int ans = 0, cnt = 0 ;

        for( int i = 0 ; i < n ; i++ ) {
            for( int j = i+1 ; j < n ; j++ ) {
                int prev = arr[i] ;
                int curr = arr[j] ;
                int next = prev + curr ;

                if( st.find(next) != st.end() ) cnt = 2 ;
                
                while ( st.find(next) != st.end() ) {
                    cnt++ ;
                    int temp = curr ; 
                    curr = next ;
                    prev = temp ;
                    next = curr + prev ;
                }

                ans = max(ans, cnt ) ;
            }
        }

        return ans ;
    }
};