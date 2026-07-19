class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> vis(26), num(26) ; 
        for( char ch : s ) num[ch-'a']++ ; 

        string st ; 
        for( char ch : s ) {
            if( !vis[ch-'a'] ) {
                while( !st.empty() && st.back() > ch ) {
                    if( num[st.back()-'a'] > 0 ) {
                        vis[st.back()-'a'] = 0 ; 
                        st.pop_back(); 
                    }
                    else break ;
                }
                vis[ch-'a'] = 1 ; 
                st.push_back(ch) ; 
            }
            num[ch-'a']-- ;
        }

        return st;
    }
};