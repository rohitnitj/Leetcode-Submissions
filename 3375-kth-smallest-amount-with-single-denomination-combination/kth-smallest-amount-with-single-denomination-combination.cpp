typedef long long ll ; 

class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size() ; 

        vector<ll> subset_lcm(1 << n ) ; 
        for( int mask = 1 ; mask < ( 1 << n ) ; mask++ ) {
            ll curr_lcm = 1 ; 

            for( int i = 0 ; i < n ; i++ ) {
                if( ( mask >> i ) & 1 ) {
                    curr_lcm = lcm(curr_lcm, (ll)coins[i] ) ; 
                }
            }

            subset_lcm[mask] = curr_lcm ; 
        }

        auto count_multiples = [&](ll x ) {
            ll cnt = 0 ; 

            for( int mask = 1 ; mask < ( 1 << n ) ; mask++ ) {
                int set_bits = __builtin_popcount(mask ) ; 

                if( set_bits & 1 ) cnt += x / subset_lcm[mask] ;
                else cnt -= x / subset_lcm[mask] ; 
            }

            return cnt ; 
        };

        ll left = 1 ; 
        ll right = (ll)*min_element(coins.begin(), coins.end() ) * k ; 
        ll ans = right ; 

        while( left <= right ) {
            ll mid = left + ( right - left ) / 2 ; 
            
            if( count_multiples(mid) >= k ) {
                ans = mid ; 
                right = mid - 1 ; 
            }
            else{
                left = mid + 1 ; 
            }
        }

        return ans;
    }
};