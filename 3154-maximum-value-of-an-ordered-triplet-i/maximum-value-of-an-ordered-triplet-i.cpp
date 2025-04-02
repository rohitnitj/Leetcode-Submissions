typedef long long ll ;
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        ll ans = 0;
        int n = nums.size() ;

        for( int i = 0 ; i < n ; i++ ) {
            for( int j = i+1; j < n ; j++ ) {
                for( int k = j+1 ; k < n ; k++ ) {
                    ll temp = (nums[i] - nums[j]) * (ll)nums[k] ;  
                    ans = max(ans, temp ) ;                                    
                }
            }
        }

        return ans;
    }
};