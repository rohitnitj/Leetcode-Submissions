class Solution {
public:
    string compressedString(string word) {

        int n = word.size() ;
        string ans = "" ;
        if( n == 1 ) return to_string(1) + word ;

        int cnt = 1 ;
        for( int i = 0 ; i < n-1 ; i++) {
            if( word[i+1] == word[i] ) cnt++ ;
            else{
                int quot = cnt / 9 ;
                int rem = cnt % 9 ;
                while( quot--) ans += to_string(9) + word[i] ;
                if( rem > 0 ) ans += to_string(rem) + word[i] ;
                cnt = 1 ;
            }
        }

        if( cnt > 1 ) {
            int quot = cnt / 9 ;
            int rem = cnt % 9 ;
            while( quot--) ans += to_string(9) + word[n-1] ;
            if( rem > 0 ) ans += to_string(rem) + word[n-1] ;
        }

        if( word[n-1] != word[n-2] && n > 1) ans += to_string(1) + word[n-1] ;

        return ans ; 

    }
};