#define ll long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        ll n = nums.size();
        ll badi = -1, mini = -1, maxi = -1, ans = 0 ;

        for( int i = 0 ; i < n ; i++ ) {
            if( nums[i] < minK || nums[i] > maxK ) badi = i ;
            if( nums[i] == minK ) mini = i ;
            if( nums[i] == maxK ) maxi = i ;
            ans += max(0LL, min(maxi, mini) - badi );
        }

        return ans ;
    }
};