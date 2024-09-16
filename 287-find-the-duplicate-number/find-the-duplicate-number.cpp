class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> mpp ;
        int n = nums.size() ;

        for( int i = 0 ; i < n; i++ ) {
            int val = nums[i] ;
            mpp[val]++ ;
            if( mpp[val] > 1 ) return val ;
        }

        return -1 ;
    }
};
