class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> st ;
        
        for( int num : nums ) {
            while( !st.empty() ) {
                int top = st.back() ; 

                int g = gcd(num, top ) ;
                if( g == 1 ) break; 
                
                num = lcm(top, num ) ;
                st.pop_back() ;
            }
            st.push_back(num ) ;
        }

        return st ;
    }
};