class Solution {
private:    
    void func(string &tiles, string temp, vector<bool> &used, unordered_set<string> &st ) {
        st.insert(temp) ;

        for( int i = 0 ; i < tiles.length() ; i++ ) {
            if( !used[i] ) {
                used[i] = true ;
                func(tiles, temp + tiles[i], used, st ) ;
                used[i] = false ;
            }
        }
    }

public:
    int numTilePossibilities(string tiles) {
        int n = tiles.size() ;
        unordered_set<string> st ;
        vector<bool> used(n, false ) ;

        func(tiles, "", used, st ) ;
        
        return st.size()-1 ;
    }
};