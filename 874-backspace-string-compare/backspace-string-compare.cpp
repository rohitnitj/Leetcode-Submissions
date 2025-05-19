class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string s1, t1 ;
        
        for( char a: s ) {
            if( a == '#' && s1.size() ) s1.pop_back() ;
            else if( a != '#' ) s1.push_back(a) ;
        }

        for( char a : t ) {
            if( a == '#' && t1.size() ) t1.pop_back() ;
            else if( a != '#' ) t1.push_back(a) ;
        }

        return s1 == t1 ;
    }
};