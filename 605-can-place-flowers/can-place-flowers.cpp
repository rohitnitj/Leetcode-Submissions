class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int sz = flowerbed.size() ;

        if( sz == 1 ) {
            if( flowerbed[0] == 0 ) n-- ;
            return n <= 0 ;
        }

        for( int i = 0 ; i < sz ; i++ ) {
            if( flowerbed[i] == 0 ) {
                if( i == 0 ) {
                    if( flowerbed[i+1] == 0 ) {
                        flowerbed[i] = 1 ;
                        n-- ;
                    }
                }

                else if( i == sz-1 ) {
                    if( flowerbed[i-1] == 0 ) {
                        flowerbed[i] = 1 ;
                        n-- ;
                    }
                }

                else if( flowerbed[i-1] == 0 && flowerbed[i+1] == 0 ) {
                    flowerbed[i] = 1 ;
                    n-- ;
                }
            }
        }

        return n <= 0 ;
    }
};