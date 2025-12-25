typedef long long ll ;

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int  n = happiness.size() ;
        sort( happiness.rbegin(), happiness.rend() );

        ll ans = 0 ;
        for( int i = 0 ; i < min(k, n ) ; i++ ) {
            ans += max(0LL, happiness[i] - ll(i) ) ;
        }

        return ans ; 
    }
};