class Solution {
private:
    void generatePermutaions(string &s, int idx, int n, unordered_set<string> &st ) {
        if( idx == n ) {
            st.insert(s) ;
            return ;
        }

        for( int i = idx ; i < n ; i++ ) {
            swap(s[i], s[idx] ) ;
            generatePermutaions(s, idx+1 , n, st ) ;
            swap(s[i], s[idx] ) ;
        }
    }

    void func(string &tiles, unordered_set<string> &st, string &temp, int idx, int n ) {
        if( idx == n ) {
            generatePermutaions(temp, 0, temp.size(), st ) ;
            return ;
        }

        temp.push_back(tiles[idx] ) ;
        func(tiles, st, temp, idx+1, n ) ;

        temp.pop_back() ;
        func(tiles, st, temp, idx+1, n ) ;

    }

public:
    int numTilePossibilities(string tiles) {
        unordered_set<string> st ;
        string temp ;
        int n = tiles.size() ;
        func(tiles, st, temp, 0, n ) ;

        return st.size()-1 ;
    }
};