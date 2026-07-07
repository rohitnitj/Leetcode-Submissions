typedef long long ll ; 

class Solution {
public:
    long long sumAndMultiply(int n) {
        stack<ll> st ; 
        ll x = 0 ; 
        while( n ) {
            ll d = n % 10 ; 
            n /= 10 ; 
            st.push(d) ; 
            x += d ; 
        }

        ll num = 0 ; 
        while( !st.empty() ) {
            int d = st.top() ; 
            if( d != 0 ) {
                num *= 10  ;
                num += d ; 
            }
            st.pop() ; 
        }

        ll ans = num * x ; 
        return ans ; 
    }
};