class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq ;
        for( auto n : nums ) pq.push(n) ;
        while( --k ) pq.pop() ;
        return pq.top() ;
    }
};
