class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size() ;
        priority_queue<int> pq ;

        for(int i = 0 ; i < n ; i++ ) {
            pq.push(nums[i] ) ;
        }

        vector<int> ans(n) ;
        for( int i = n-1 ; i >= 0 ; i-- ) {
            ans[i] = pq.top() ;
            pq.pop() ;
        }

        return ans ;
    }
};