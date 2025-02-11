class Solution {
public:
    string removeOccurrences(string s, string part) {
        
        int n = part.size() ;
        string ans = "" ;

        for ( char ch : s ) {
            ans += ch ;
            if( ans.size() >= n && ans.substr(ans.size() - n ) == part ) {
                ans.erase(ans.size() - n ) ;
            }
        }

        return ans ;
    }
};