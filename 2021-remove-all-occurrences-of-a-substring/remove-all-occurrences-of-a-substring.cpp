class Solution {
private:
    vector<int> kmp(string s ) {
        vector<int> lps(s.size(), 0 ) ;
        
        for( int i = 1 ; i < lps.size() ; i++ ) {
            int prev_idx = lps[i-1] ;

            while(prev_idx > 0 && s[i] != s[prev_idx] ) {
                prev_idx = lps[prev_idx-1] ;
            }

            lps[i] = prev_idx + ( s[i] == s[prev_idx] ? 1 : 0 ) ;
        }

        return lps ;
    }

public:
    string removeOccurrences(string s, string part) {
        vector<int> lps = kmp(part ) ;
        string ans ;
        vector<int> pre_matches ;

        for( char c : s ) {
            ans.push_back(c ) ;
            int j = pre_matches.empty() ? 0 : pre_matches.back() ;

            while( j > 0 && part[j] != c ) j = lps[j-1] ;
            if( part[j] == c ) j++ ;
            pre_matches.push_back(j) ;

            if( j == part.size() ) {
                ans.resize(ans.size() - part.size() ) ;
                pre_matches.resize(pre_matches.size() - part.size() ) ;
            }
        }

        return ans ;
    }
};