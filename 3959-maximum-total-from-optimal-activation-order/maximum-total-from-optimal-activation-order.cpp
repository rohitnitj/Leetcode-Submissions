class Solution {
public:
    long long maxTotal(vector<int>& value, vector<int>& limit) {
        int n = value.size() ;

        vector<priority_queue<int>> arr(n+1 ) ;
        for( int i = 0 ; i < n ; i++ ) arr[limit[i]].push(value[i] ) ;

        long long ans = 0 ;
        for( int i = 0 ; i <= n ; i++ ) {
            int k = i ;
            while( !arr[i].empty() && k-- ) {
                ans += arr[i].top() ;
                arr[i].pop() ;
            }
        }

        return ans ;
    }   
};