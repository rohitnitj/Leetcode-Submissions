class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    
        int maxi = candies[0] ; 
        for( auto i : candies ) maxi = max(maxi, i) ;

        int limit = maxi - extraCandies ;

        vector<bool> ans ;
        for( auto i : candies ) {
            if( i >= limit ) ans.push_back(true) ;
            else ans.push_back(false ) ;
        }

        return ans ;

    }
};
