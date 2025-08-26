class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int ans = 0, maxi = 0 ;

        for( auto dim : dimensions ) {
            int l = dim[0], b = dim[1] ;
            int d = l * l + b * b ;

            if( d > maxi ) {
                maxi = d ;
                ans = l * b ; 
            }
            else if( d == maxi ) ans = max(ans, l * b ) ;
        }

        return ans ; 
    }
};