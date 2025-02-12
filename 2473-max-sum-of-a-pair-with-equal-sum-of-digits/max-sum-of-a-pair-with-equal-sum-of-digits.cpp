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

        map<int, priority_queue<int> > mpp ;

        for( auto num : nums ) {
            int dsum = digitSum(num ) ;
            mpp[dsum].push(num ) ;
        }

        int ans = -1 ;
        for( auto &it : mpp ) {
            priority_queue<int> pq = it.second ;

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