class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size() ;
        int i = 0 , j = 0 ; 
        double sum = 0.0 , max_avg = 0.0 , avg = 0.0 ;

        if( n < k ) return 0 ;

        while( j != k ) {
            sum += nums[j] ;
            j++ ;
        }
        max_avg = sum / k ;

        while( j < n ) {
            sum -= nums[i] ;
            sum += nums[j] ;
            i++ , j++ ;

            avg = sum / k ;
            max_avg = max(avg, max_avg ) ;
        } 

        return max_avg ;
    }
};