class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size() ;

        set<int> st ;
        for( int i = 0 ; i < n ; i++ ) {
            for( int j = 0 ; j < n ; j++ ) {
                if( nums[j] == key && abs( i - j ) <= k ) st.insert(i) ;
            }
        }

        vector<int> ans ;
        for( int s : st ) ans.push_back(s ) ;
        
        return ans ;
    }
};