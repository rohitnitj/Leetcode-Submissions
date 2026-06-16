class Solution {
public:
    string processStr(string s) {
        string ans = "" ; 

        for( char ch : s ) {
            if( ch == '*' ){
                if(ans.size()) ans.pop_back() ;
            }
            else if( ch == '%' ) reverse( ans.begin(), ans.end() ) ;
            else if( ch == '#' ) ans += ans ; 
            else ans += ch ; 
        }

        return ans ; 
    }
};