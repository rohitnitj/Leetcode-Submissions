class Solution {
private:
    vector<int> computeLPS(string s ) {
        int n = s.size() ;
        vector<int> lps(n, 0 ) ;

        int len = 0 ;
        int i = 1 ;

        while( i < n ) {
            if( s[i] == s[len] ) {
                len++ ;
                lps[i] = len ;
                i++ ;
            }
            else{
                if( len > 0) {
                    len = lps[len-1] ;
                }
                else{
                    i++ ;
                }
            }
        }

        return lps ;
    }

    bool isSubstringKMP(string a, string b , vector<int> &lps ) {
        int a_len = a.length() ;
        int b_len = b.length() ;
        int i = 0, j = 0 ;

        while( i < a_len ) {
            if( a[i] == b[j] ) {
                i++ ;
                j++ ;
                if( j == b_len ) return true ;
            }
            else{
                if( j > 0 ) {
                    j = lps[j-1] ;
                }
                else{
                    i++ ;
                }
            }
        }

        return false ;
    }

public:
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size() ;
        unordered_set<string> st ;
        vector<string> ans ;
        
        for( int i = 0 ; i < n ; i++ ) {
            for( int j = 0 ; j < n ; j++ ) {

                if( i != j ) {
                    vector<int> lps = computeLPS(words[j] ) ;
                    
                    if( isSubstringKMP( words[i], words[j] , lps ) ) {
                        st.insert(words[j] ) ;
                    }
                }
            }
        }

        for( auto it : st ) {
            ans.push_back(it ) ;
        }
        
        return ans ;
    }
};