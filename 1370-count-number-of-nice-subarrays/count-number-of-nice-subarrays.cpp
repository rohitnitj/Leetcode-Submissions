class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size() ; 

        map<int, int> mpp ; 
        mpp[0]++ ; 

        int odd = 0, ans = 0 ; 

        for( int num : nums ) {
            odd += ( num & 1 ) ; 
            ans += mpp[odd-k] ; 
            mpp[odd]++ ; 
        }

        return ans ; 
    }
};