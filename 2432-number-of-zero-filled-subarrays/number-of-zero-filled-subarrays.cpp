typedef long long ll ;

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        ll cnt = 0, ans = 0 ;
        for( auto a : nums ) {
            if( a == 0 ) cnt++ ;
            else {
                ans += ( cnt * ( cnt + 1 ) ) / 2 ;
                cnt = 0 ;
            }
        }
        ans += ( cnt * ( cnt + 1 ) ) / 2 ;
        return ans ;
    }
};