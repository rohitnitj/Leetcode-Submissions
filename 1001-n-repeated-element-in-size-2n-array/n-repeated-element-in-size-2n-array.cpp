class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size() ;
        vector<int> arr(1e5) ;

        for( int num : nums ) {
            if( arr[num] >= 1 ) return num ;
            arr[num]++ ;
        }

        return -1 ; 
    }
};