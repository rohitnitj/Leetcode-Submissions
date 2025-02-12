class Solution {
private:
    int digitSum(int n ){
        int sum = 0 ;
        while( n ) {
            sum += n % 10 ;
            n /= 10 ;
        }
        return sum ;
    }

public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size() ;

        vector< priority_queue<int, vector<int>, greater<int> >> mpp(82 ) ;

        for( auto num : nums ) {
            int dsum = digitSum(num ) ;
            mpp[dsum].push(num ) ;

            if(mpp[dsum].size() > 2 ) {
                mpp[dsum].pop();
            }
        }

        int ans = -1 ;
        
        for( auto &pq : mpp ) {
            if( pq.size() >= 2 ) {
                
                int first = pq.top() ;
                pq.pop() ;
                int second = pq.top() ;

                ans = max( ans, first + second ) ;
            }
        }

        return ans ;
    }
};