class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int,int> mpp ;
        for( int a : arr ) mpp[a]++ ;
        int ans = -1 ;
        for( auto &[v, f] : mpp ) if( v == f ) ans = max(ans, v ) ;
        return ans ;
    }
};
