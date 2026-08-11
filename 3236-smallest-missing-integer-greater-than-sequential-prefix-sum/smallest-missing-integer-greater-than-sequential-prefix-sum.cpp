class Solution {
public:
    int missingInteger(std::vector<int>& nums) {
        int n = nums.size() ; 

        set<int> st ; 
        for( int num : nums ) st.insert( num ) ; 

        int sum = nums[0] ; 
        for( int i = 1 ; i < n; i++ ) {
            if( nums[i] == nums[i-1] + 1 ) sum += nums[i] ; 
            else break ; 
        }

        while( st.count(sum ) ) sum++ ; 
        return sum ; 
    }
};