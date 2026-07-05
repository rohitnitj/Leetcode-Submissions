class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size() ; 

        vector<int> pref = nums, suff = nums ; 
        for( int i = 1 ; i < n ; i++ ) pref[i] = max( pref[i], pref[i-1] ) ; 
        for( int i = n-2 ; i >= 0 ; i-- ) suff[i] = max( suff[i], suff[i+1] ) ; 

        int ans = 0 ; 
        for( int i = 0 ; i + k < n; i++ ) {
            int val = pref[i] + suff[i+k] ; 
            ans = max(ans, val ) ; 
        }   

        return ans ; 
    }
};