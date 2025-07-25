class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int> st ;
        int maxi = -101;

        for( int num : nums ) {
            if( num > 0 ) st.insert(num) ;
            if( num <= 0 ) maxi = max(maxi, num ) ;
        }

        if( st.size() == 0 ) return maxi ;

        int ans = 0 ;
        for( int num : st ) ans += num ; 

        return ans ;
    }
};