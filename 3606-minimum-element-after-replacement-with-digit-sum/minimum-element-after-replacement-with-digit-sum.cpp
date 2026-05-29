class Solution {
public:
    int findSum( int n ) {
        int sum = 0 ; 
        while( n ) {
            sum += n % 10 ; 
            n /= 10 ; 
        }
        return sum ; 
    }

    int minElement(vector<int>& nums) {
        int mini = findSum(nums[0]) ; 
        for( int num : nums ) mini = min(mini, findSum(num)) ; 
        return mini ; 
    }
};