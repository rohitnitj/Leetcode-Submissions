class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size() ;
        unordered_set<int> st ;
        unordered_map<int,int> mpp ;

        for( auto num : nums ) st.insert(num) ;
        int dist = st.size() ;
        int cnt = 0 ;

        int i = 0 ;
        for( int j = 0 ; j < n ; j++ ) {
            mpp[nums[j]]++ ;

            while( mpp.size() == dist ) {
                cnt += (n-j) ;
                mpp[nums[i]]-- ;
                
                if(mpp[nums[i]] == 0 ) mpp.erase(nums[i] ) ;
                i++ ;
            }
        }

        return cnt ;
    }
};