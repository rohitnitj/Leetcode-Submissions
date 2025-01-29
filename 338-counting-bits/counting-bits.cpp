class Solution {
private:    
    int findOne(int n ) {
        int cnt = 0 ;

        while( n ) {
            cnt += ( n & 1 ) ;
            n = n >> 1 ;
        }

        return cnt ;
    }

public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0 ) ;
        
        for(int i = 0 ; i <= n ; i++ ) {
            int one = findOne(i ) ;
            ans[i] = one ;
        }

        return ans;
    }
};