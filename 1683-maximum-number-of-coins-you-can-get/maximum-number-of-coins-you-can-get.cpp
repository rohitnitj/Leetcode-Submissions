class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size() ;
        sort(piles.rbegin(), piles.rend()) ;

        int ans = 0, cnt = n / 3 ; 
        for( int i = 1 ; i < 2 * cnt ; i += 2 ) {
            ans += piles[i] ; 
        }

        return ans ; 
    }
};