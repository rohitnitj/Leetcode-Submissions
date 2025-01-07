class Solution {
private:
    bool isSubstring(string a, string b ) {
        int a_len = a.length() ;
        int b_len = b.length() ;

        for(int i = 0 ; i < a_len ; i++ ) {
            string substr = "" ;

            for( int j = i ; j < a_len ; j++ ) {
                substr += a[j] ;

                if( substr == b ) {
                    return true ;
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
                    if( isSubstring( words[i], words[j] ) ) {
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