class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size() ;
        int cnt = 0 ;

        for( int &f : fruits ) {
            bool fl = false ;

            for( int &b : baskets ) {
                if( b >= f ) {
                    b = -1 ;
                    fl = true ;
                    break ;
                }
            }

            if( !fl ) cnt++ ;
        }

        return cnt ;
    }
};