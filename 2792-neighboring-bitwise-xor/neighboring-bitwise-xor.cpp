class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int exor = 0 ;
        for( auto d : derived ) {
            exor ^= d ;
        }
        return exor == 0 ;
    }
};