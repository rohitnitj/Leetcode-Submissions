class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size() ;
        vector<int> org(n+1, 0 ) ;
        int maxi = 0 ;
        for( int i = 0 ; i < n ; i++ ) {
            org[i+1] = org[i] + gain[i] ;
            maxi = max( maxi ,org[i+1] ) ;
        }  
        return maxi ;  
    }
};