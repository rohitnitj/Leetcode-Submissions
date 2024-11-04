class Solution {
public:
    string compressedString(string word) {
        int n = word.size() ;
        string ans = "" ;
        int i = 0 ;

        while( i < n ) {
            int j = 0 ; 
            char ch = word[i] ;

            while( i < n && j < 9 && word[i] == ch ) {
                i++ ; 
                j++ ;
            }

            ans += to_string(j) + ch ;
        }

        return ans ;
    }
};