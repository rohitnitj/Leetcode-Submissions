class Solution {
public:
    int gcd(int a, int b) {
        while( b ) {
            int temp = a % b ; 
            a = b ; 
            b = temp ;
        }
        return a ;
    }

    long long lcm(int a, int b ) {
        return ( long long ) a / gcd(a, b ) * b ;
    }

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