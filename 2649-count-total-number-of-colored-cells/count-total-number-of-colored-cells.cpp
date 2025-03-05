typedef long long ll ;

class Solution {
public:
    long long coloredCells(int n ) {
        return ll(1 + 2 * ll(n) * ll(n-1 )) ;
    }
};