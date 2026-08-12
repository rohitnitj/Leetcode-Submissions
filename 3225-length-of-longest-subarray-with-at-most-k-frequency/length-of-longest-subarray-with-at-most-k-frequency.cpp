class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size() ;
        unordered_map<int,int> freq ;
        int left = 0 , right = 0 , maxLength = 0 ;

        while( right < n ) {
            freq[nums[right]]++ ;

            while( freq[nums[right]] > k ) {
                freq[nums[left]]-- ;
                left++ ;
            }

            maxLength = max( maxLength, right - left + 1 ) ;
            right++ ;
        }

        return maxLength ;
    }
};
