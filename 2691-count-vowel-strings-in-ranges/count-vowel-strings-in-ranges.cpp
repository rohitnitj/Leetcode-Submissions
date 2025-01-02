class Solution {
private:
    bool is_vowel(char ch ) {
        vector<char> vowels = {'a', 'e', 'i', 'o', 'u' } ;
        bool flag = false ;
        for ( auto it : vowels ) {
            if( ch == it ) flag = true ;
        }
        return flag ;
    }

    bool func(string s ) {
        return is_vowel(s[0]) && is_vowel(s[s.size()-1] ) ;
    }

public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int w_size = words.size() ;
        int q_size = queries.size() ;

        vector<int> arr(w_size, 0) ;
        int cnt = 0 ;
        for( int i = 0 ; i < w_size ; i++ ) {
            if( func( words[i] ) ) {
                cnt++ ;
            }
            arr[i] = cnt ;
        }

        vector<int> ans ;
        for( auto q : queries ) {
            if( q[0] == 0 ) {
                ans.push_back(arr[q[1]]) ;
            }
            else {
                ans.push_back(arr[q[1]] - arr[q[0]-1] ) ;
            }
        }

        return ans ;
    }
};