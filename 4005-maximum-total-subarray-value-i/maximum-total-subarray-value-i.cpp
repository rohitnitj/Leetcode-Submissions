typedef long long ll ; 

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        ll mini = *min_element( nums.begin(), nums.end() ) ;
        ll maxi = *max_element( nums.begin(), nums.end() ) ;
        ll ans = k * ( maxi - mini ) ;
        return ans ; 
    }
};