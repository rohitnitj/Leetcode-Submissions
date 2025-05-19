class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size() ;
        int index = 0 ;

        int i = 0 ;
        while( i < n ) {
            char curr_char = chars[i] ;
            int j = i ;

            while( j < n && chars[j] == curr_char ) {
                j++ ;
            }

            chars[index++] = curr_char ;
            int cnt = j - i ;

            if ( cnt > 1 ) {
                for( char c : to_string(cnt ) ) {
                    chars[index++ ] = c ;
                }
            }

            i = j ;
        }

        return index ;
    }
};