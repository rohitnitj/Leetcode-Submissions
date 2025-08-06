class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size() ;

        vector<int> maxima, minima ;
        for( int i = 1 ; i < n-1 ; i++ ) {
            if( nums[i] == nums[i-1] || nums[i] == nums[i+1] ) return false ;
            if( nums[i-1] < nums[i] && nums[i] > nums[i+1] ) maxima.push_back(i) ;
            if( nums[i-1] > nums[i] && nums[i] < nums[i+1] ) minima.push_back(i) ;
        }

        if( maxima.size() == 1 && minima.size() == 1 && maxima[0] < minima[0] ) return true ;
        return false ;
    }
};