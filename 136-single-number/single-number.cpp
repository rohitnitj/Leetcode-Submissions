class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int exor = 0 ;
        for( auto n : nums ) {
            exor ^= n ;
        }
        return exor ;
    }
};