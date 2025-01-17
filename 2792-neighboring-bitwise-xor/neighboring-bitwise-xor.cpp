class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int sum = 0 ;
        for( auto d : derived ) {
            sum += d ;
        }
        return ( sum % 2 == 0 ) ;
    }
};