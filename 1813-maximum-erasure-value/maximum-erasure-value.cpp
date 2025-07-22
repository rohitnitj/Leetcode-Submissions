class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size() ;\
        
        set<int> st ;
        int i = 0, j = 0 ;
        int sum = 0, ans = 0 ;
        
        for( j = 0 ; j < n ; j++ ) {
            int val = nums[j] ;
            while( st.find(val) != st.end() ) {
                sum -= nums[i] ;
                st.erase(nums[i] ) ;
                i++ ;
            }
            sum += val ;
            st.insert(val) ;
            ans = max(ans, sum ) ;
        }
        
        return ans ;
    }
};