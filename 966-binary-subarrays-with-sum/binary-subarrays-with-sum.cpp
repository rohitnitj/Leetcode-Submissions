class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size() ; 

        map<int, int> freq ; 
        freq[0] = 1 ;
        
        int ans = 0 ; 
        int sum = 0 ; 

        for( int num : nums ) {
            sum += num ; 
            if( freq[sum-goal] > 0 ) {
                ans += ( freq[sum - goal] ) ; 
            }
            freq[sum]++ ; 
        }

        return ans ; 
    }
};