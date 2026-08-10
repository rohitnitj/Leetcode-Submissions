class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort( prices.rbegin(), prices.rend() ) ; 
        sort( discounts.rbegin(), discounts.rend() ) ; 

        double ans = 0.0 ; 
        int i = 0 ; 
        for( int price : prices ) {
            int d = 0 ; 
            if( i < discounts.size() ) d = discounts[i++] ;

            double val = (double)( price * ( 100 - d ) ) / 100 ; 
            ans += val ; 
        }   

        return ans ; 
    }
};