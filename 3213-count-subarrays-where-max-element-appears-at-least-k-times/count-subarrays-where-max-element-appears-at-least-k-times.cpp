typedef long long ll;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        ll n = nums.size();

        ll maxi = nums[0], ans = 0 ;
        for( ll i =0 ; i < n ; i++ ) maxi = max(maxi, (ll)nums[i]) ;
        ll maxRange = 0, i = 0 ;

        for( ll j = 0 ; j < n ; j++ ) {
            if( nums[j] == maxi ) maxRange++ ;
            
            while( maxRange == k ) {
                if( nums[i] == maxi ) maxRange-- ;
                i++ ;
            }

            ans += i ;
        }

        return ans ;
    }
};