class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n = apple.size(); 
        int m = capacity.size() ;

        sort( capacity.rbegin(), capacity.rend() ) ;

        int i = 0, val = 0, cnt = 0 ;

        for( int a : apple ) {
            while( a > val ) {
                val += capacity[i] ;
                cnt++ ;
                i++ ;
            }

            val -= a ;
        }

        return cnt ; 
    }
};