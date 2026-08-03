typedef long long ll ; 

class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        int n = nums.size() ; 
        ll ans = 0 ; 

        for( int i = 0 ; i < n ; i++ ) {
            ll a = nums[i] ; 

            for( int j = i+1 ; j < n; j++ ) {
                ll b = nums[j] ;
                ll temp = a * b / ( gcd(a, b) * gcd(a, b ) ) ; 
                ans = max(ans, temp ) ; 
            }
        }

        return ans ;
    }
};