class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size() ;

        priority_queue<int, vector<int>, greater<int> > pq ;
        for( int i = 1; i < n; i++ ){
            pq.push(nums[i] ) ;
        }

        int ans = nums[0] ;
        for( int i = 0 ; i < 2 ; i++ ) {
            if( pq.size() ) {
                ans += pq.top() ;
                pq.pop() ;
            }
        }

        return ans ; 
    }
};