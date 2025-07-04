class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int ans = 0;
        
        while( k != 1 ) {
            int t = log2(k) ;
            if( ( ( long long )1 << t ) == k ) t-- ;
            k = k - ( ( long long)1 <<t ) ;
            if( operations[t]) ans++ ;
        }

        return 'a' + ( ans % 26 ) ;
    }
};