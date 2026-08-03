class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0, close = 0 ; 
        for( char ch : s ) {
            if( ch == '(' ) open++ ; 
            else open ? open-- : close++ ; 
        }
        return open + close ; 
    }
};