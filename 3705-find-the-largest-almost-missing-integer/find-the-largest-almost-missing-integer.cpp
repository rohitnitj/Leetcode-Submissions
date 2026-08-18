class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        if( k == n ) {
            int maxi = -1 ; 
            for( int num : nums ) maxi = max(maxi, num ) ; 
            return maxi ; 
        }
        
        if( k == 1 ) {
            map<int, int> freq ; 
            for( int num : nums ) freq[num]++ ; 

            int maxi = -1 ; 
            for( auto &[num, cnt ] : freq ) {
                if( cnt == 1 ) maxi = max(maxi, num ) ; 
            }

            return maxi ; 
        }
        
        int first = nums[0];
        int last = nums[n-1];
        
        for(int i = 1; i < n; i++) {
            if(nums[i] == first) first = -1;
        }
        
        for(int i = 0; i < n - 1; i++) {
            if(nums[i] == last) last = -1;
        }
        
        return max(first, last);
    }
};