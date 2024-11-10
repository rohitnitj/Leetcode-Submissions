class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size() ;

        vector<long long> preSum(n+1, 0 ) ;
        for( int i = 0 ; i < n; i++ ) {
            preSum[i+1] = preSum[i] + nums[i] ;
        }
        
        int ans = INT_MAX ;
        deque<int> dq ;

        for( int i = 0 ; i < n+1 ; i++ ) {
            
            while( !dq.empty() && preSum[i] - preSum[dq.front()] >= k ) {
                ans = min(ans, i-dq.front()) ;
                dq.pop_front() ;
            }

            while( !dq.empty() && preSum[i] <= preSum[dq.back()] ) {
                dq.pop_back() ;
            }

            dq.push_back(i) ;
        }

        return ans == INT_MAX ? -1 : ans ;
    }
};