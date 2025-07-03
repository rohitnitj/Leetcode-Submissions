class Solution {
public:

    int func(vector<int>& prices, int fee ) {
        int n = prices.size() ;

        int aheadNotBuy, aheadBuy , currBuy, currNotBuy ;
        aheadNotBuy = aheadBuy = 0 ;

        for( int ind = n-1; ind >= 0 ; ind-- ) {

            currNotBuy = max( prices[ind] - fee + aheadBuy, 0 + aheadNotBuy ) ;
            currBuy = max( -prices[ind] + aheadNotBuy ,0 + aheadBuy ) ;

            aheadBuy = currBuy ;
            aheadNotBuy = currNotBuy ;
        }
        
        return aheadBuy ;
    }

    int maxProfit(vector<int>& prices, int fee) {
        return func(prices, fee ) ;
    }
};