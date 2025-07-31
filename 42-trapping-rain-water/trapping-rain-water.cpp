class Solution {
public:
    int trap(vector<int>& h) {
        int l = 0 ;
        int r = h.size() - 1; 
        int lmax = INT_MIN ;
        int rmax = INT_MIN ;
        int ans = 0 ;

        while( l < r ){
            lmax = max ( lmax , h[l] ) ;
            rmax = max ( rmax , h[r] ) ;
            ans += ( lmax < rmax ) ? lmax - h[l++] : rmax - h[r--] ;
        }
        
        return ans ;
    }
};