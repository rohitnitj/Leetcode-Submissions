class Solution {
private:    
    bool isSubset(string a, vector<int> freq_b ) {

        vector<int> freq_a(26, 0 ) ;
        for ( char ch : a ) freq_a[ch-'a']++ ;

        bool flag = true ;
        for( int i = 0 ; i < 26 ; i++ ) {
            if( freq_b[i] != 0 ) {
                if( freq_b[i] > freq_a[i] ) {
                    flag = false ;
                    break ;
                }
            }
        }

        return flag ;
    }

public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans ;

        vector<int> freq(26, 0 ) ;
        for( auto word : words2 ) {
            
            vector<int> temp(26, 0 ) ;
            for( auto ch : word ) {
                temp[ch-'a']++ ;
            }

            for( int i = 0 ; i < 26 ; i++ ) {
                freq[i] = max( freq[i], temp[i] ) ;
            }            
        }

        for( auto word1 : words1 ) {
            if( isSubset( word1, freq ) ) {
                ans.push_back( word1 ) ;
            }
        }

        return ans ;
    }
};