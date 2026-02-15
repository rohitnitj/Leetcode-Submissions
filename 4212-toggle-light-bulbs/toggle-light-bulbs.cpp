class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        
        map<int, int> mpp ;
        for( int b : bulbs ) mpp[b]++ ;

        vector<int> ans ; 
        for( auto &[b, c] : mpp ) if( c & 1 ) ans.push_back(b) ;

        return ans ; 
    }
};