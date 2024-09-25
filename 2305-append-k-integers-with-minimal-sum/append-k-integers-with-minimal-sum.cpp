class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        long long ans = (long long )k * ( k  + 1 ) / 2 ;
        for( int num : set<int>(begin(nums), end(nums ) ) ) 
            if( num <= k ) ans += (++k ) - num ;
        return ans ;
    }
};