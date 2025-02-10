class Solution {
private:
    bool isChar(char ch ) {
        return ( ch >= 'a' && ch <= 'z' ) ;
    }

    bool isDigit(char ch ) {
        return ( ch >= '0' && ch <= '9' ) ;
    }

public:
    string clearDigits(string s ) {
        int n = s.size() ;
        stack<char> st ;

        for( int i = 0 ; i < n ; i++ ) {
            if( isDigit(s[i]) ) st.pop() ;
            else if( isChar(s[i] ) ) st.push(s[i] ) ;
        }

        string ans = "" ;
        while( !st.empty() ) {
            ans += st.top() ;
            st.pop() ;
        }

        reverse(ans.begin(), ans.end() ) ;
        return ans ;
    }
};