class Solution {
    public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size() ;
        int i = 0, j = 0 ;
        int cnt = 0 ;
        
        while( i < n ) {
            while( j - i < k && i < n) {
                if( j > 0 && colors[j%n] == colors[(j-1)%n] ) {
                    i = j;
                }
                j++ ;
            }
            if( i >= n ) return cnt ;
            cnt++ ;
            i++ ;
            if( colors[j%n] ==  colors[(j-1) % n]) i = j  ;
            j++ ; 
        }

        return cnt ;
    }
};