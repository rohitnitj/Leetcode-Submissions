typedef long long ll ; 

class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n = nums.size() ;

        if( n == 1 ) return -1 ; 

        vector<ll> pref(n) ; 
        pref[0] = nums[0] ;
        for( int i = 1; i < n; i++ ) pref[i] = pref[i-1] + nums[i] ;

        // first index 
        for( int i = 1; i < n ; i++ ) {
            if( nums[i] == 0 ) return 0 ; 
        }

        // last index  
        if( pref[n-2] == 1 ) return n-1 ;
        
        // rest index 
        ll prod = 1LL ; 
        int ans = n ; 
        
        for( int i = n-2 ; i >= 1 ; i-- ){
            if( prod > pref[i-1] ) {
                if( ans == n ) return -1 ; 
                else return ans ; 
            }
            prod *= nums[i+1] ; 
            if( pref[i-1] == prod ) ans = i ; 
        }

        if( ans == n ) return -1 ; 
        return ans ; 
    }
};