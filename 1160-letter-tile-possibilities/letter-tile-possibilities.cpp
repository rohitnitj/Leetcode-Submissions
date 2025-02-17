class Solution {
private:    
    int func(vector<int> &freq ) {
        int ans = 0 ;

        for( int i = 0 ; i < 26; i++ ) {
            if( freq[i] == 0 ) continue; 

            ans++ ;
            freq[i]-- ;
            ans += func(freq) ;
            freq[i]++ ;
        }

        return ans ;
    }

public:
    int numTilePossibilities(string tiles) {
        int n = tiles.size() ;

        vector<int> freq(26, 0 ) ;
        for( auto ch : tiles ) {
            freq[ch-'A']++ ;
        }
        
        return func(freq )  ;
    }
};