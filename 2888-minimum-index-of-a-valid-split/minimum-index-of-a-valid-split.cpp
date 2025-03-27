class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int temp = nums[0], cnt = 0, total = 0, n = nums.size() ;
        
        for( int num : nums ) {
            if( num == temp ) cnt++ ;
            else cnt-- ;
            if( cnt == 0 ) {
                temp = num ;
                cnt = 1 ;
            }
        }

        for( int num : nums ) {
            if( num == temp ) total++ ;
        }

        int pcnt = 0 ;
        for( int i = 0 ; i < n-1 ; i++ ) {
            if( nums[i] == temp ) pcnt++ ;
            if( pcnt * 2 > i+1 && ( total - pcnt ) * 2 > n-i-1 ) return i ;
        }

        return -1 ;
    }
};