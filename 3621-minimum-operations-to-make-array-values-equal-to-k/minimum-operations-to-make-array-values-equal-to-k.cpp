class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> st ;
        bool f = false ;
        for( int num : nums ) {
            if( num < k ) return -1 ;
            if( num == k ) f = true ;
            st.insert(num) ;
        }
        return f ? st.size()-1 : st.size() ;
    }
};