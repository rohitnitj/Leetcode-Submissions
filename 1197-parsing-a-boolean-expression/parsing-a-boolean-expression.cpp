class Solution {
private:
    bool parseOr (vector<int> &ans ) {
        int mask = ans[0] ;
        for( int i = 1 ; i < ans.size() ;i++ ) 
            mask |= ans[i] ;
        return mask ;
    }

    bool  parseAnd (vector<int> &ans ){
        int mask = ans[0] ;
        for( int i = 1; i < ans.size() ; i++ ) 
            mask &= ans[i] ;
        return mask ;
    }

public : 
    bool parseBoolExpr(string s ) {
        int n = s.size() ;
        stack<int> st ;

        for( int i = 0 ; i < n; i++ ) {
            if( s[i] == ',' ) continue; 

            if( s[i] == ')' ) {
                vector<int> ans ;

                while( st.top() != '&' && st.top() != '|' && st.top() != '!' ) {
                    char ch = st.top() ;
                    st.pop() ;

                    if( ch == 't' ) ans.push_back(1) ;
                    if( ch == 'f' ) ans.push_back(0) ;
                }

                char ch = st.top() ;
                st.pop() ;

                if( ch == '&' ) {
                    if( parseAnd(ans)) st.push('t') ;
                    else st.push('f') ;
                }

                else if ( ch == '|' ) {
                    if ( parseOr(ans )) st.push('t') ;
                    else st.push('f') ;
                }

                else if ( ch == '!' ) {
                    if( ans[0] == 0 ) st.push('t') ;
                    else st.push('f') ;
                }
            }

            else st.push(s[i]) ;
        }

        return (st.top() == 't') ;
    }
};