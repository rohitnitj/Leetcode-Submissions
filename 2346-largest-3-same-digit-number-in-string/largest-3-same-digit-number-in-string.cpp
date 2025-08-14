class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size() ;
        int maxi = -1 ;

        for( int i = 0 ; i < n-2 ; i++ ) {
            int a = num[i] - '0' ;
            int b = num[i+1] - '0' ;
            int c = num[i+2] - '0' ;
            if( a == b && b == c ) maxi = max(maxi, a ) ;                        
        }

        if( maxi == -1 ) return "" ;
        else {
            string ans = to_string(maxi) + to_string(maxi) + to_string(maxi) ;
            return ans ;
        }

        return "" ;
    }
};