class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size() ;
        vector<int> ans ;
        unordered_set<int> st ;

        for( int i = 0 ; i < n; i++ ) {
            for( int j = 0 ; j < n ; j++ ) {
                for( int k = 0 ; k < n ; k++ ) {
                    if( i != j && j != k  && i != k ) {
                        int temp = 100*digits[i] + 10*digits[j] + digits[k] ;
                        if(  ( temp & 1 ) ) continue ; 
                        else if( temp >= 100 ) st.insert(temp) ;
                    }                    
                }
            }
        }

        for( int s : st ) ans.push_back(s ) ;
        sort(ans.begin(), ans.end() );

        return ans ;
    }
};