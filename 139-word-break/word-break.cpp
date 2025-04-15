class Solution {
private:
    bool compare(string s, string w, int i ) {
        for( int k = 0 ; k < w.size() ; k++ ) {
            if( s[k+i] != w[k] ) return false ;
        }
        return true ;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size() ;
        vector<bool> dp(n+1, false);
        dp[n] = true ;

        for( int i = n-1 ; i >= 0 ; i-- ) {
            for( auto w : wordDict) {
                int m = w.size() ;

                if( i + m <= n &&  compare(s, w, i ) ) dp[i] = dp[i + m] ;
                if( dp[i] ) break ;                
            }
        }

        return dp[0] ;
    }
};