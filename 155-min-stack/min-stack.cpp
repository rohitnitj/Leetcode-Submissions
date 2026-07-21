typedef long long ll ; 

class MinStack{
    stack<ll> st ; 
    ll mini ; 

public:
    MinStack() {
        mini = INT_MAX ; 
    }
    
    void push(int value) {
        ll val = value ; 
        if( st.empty() ) {
            mini = val ; 
            st.push(val ) ;
        }
        else {
            if( val < mini ) {
                st.push( 2 * val - mini ) ;
                mini = val ; 
            }
            else st.push(val) ; 
        }
    }
    
    void pop() {
        if( st.empty() ) return ;

        ll top_val = st.top() ; 
        st.pop() ; 

        if( top_val < mini ) {
            mini = 2 * mini - top_val ; 
        }
    }
    
    int top() {
        ll top_val = st.top() ; 
        if( top_val < mini ) return mini ; 
        return top_val ; 
    }
    
    int getMin() {
        return mini ;
    }
};