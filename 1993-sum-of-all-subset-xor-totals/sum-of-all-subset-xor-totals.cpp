class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size() ; 
        int ans = 0 ; 
        for(int i = 0 ; i < (1 << n) ; i++){
            int xorSum = 0 ; 
            for(int j = 0 ; j < n ; j++){
                if(i & (1 << j)){
                    xorSum ^= nums[j] ; 
                }
            }
            ans += xorSum ; 
        }
        return ans ;      
    }
};