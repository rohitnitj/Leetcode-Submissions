class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size() ;

        vector<int> ans ;
        for( int i = 0 ; i < n - k + 1 ; i++ ) {
            map<int, int> mpp ;
            priority_queue<pair<int,int>> pq ;

            for( int j = i ; j < min(i+k, n) ; j++ ) {
                mpp[nums[j]]++ ;
            }            

            for( auto &[v, f] : mpp ) pq.push( {f, v } ) ;

            int sum = 0 ;
            for( int j = 1; j <= x && pq.size() ; j++ ) {
                sum += pq.top().second * pq.top().first ;
                pq.pop() ;
            }

            ans.push_back(sum) ;
        }

        return ans ;
    }
};