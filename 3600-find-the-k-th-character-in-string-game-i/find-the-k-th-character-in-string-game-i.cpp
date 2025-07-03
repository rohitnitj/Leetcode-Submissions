class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";
        while (s.size() < k) {
            string temp = s ;
            for( char c : temp ) s += ( c == 'z' ? 'a' : c + 1 ) ;
        }
        return s[k - 1];
    }
};
