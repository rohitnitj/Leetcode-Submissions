class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr ;
        for( auto gr : grid ) {
            for ( auto g : gr ) {
                arr.push_back(g) ;
            }
        }

        sort( arr.begin(), arr.end() ) ;
        
        int mod = arr[0] % x ;
        for( int a : arr ) {
            if ( a % x != mod ) {
                return -1 ;
                break ;
            }
        }

        int m = arr.size()/2 ;
        int mid = arr[m] ;
        int ans = 0 ;

        for( int a : arr) {
            ans += (abs(mid-a) / x ) ;
        }

        return ans ;
    }
};