class Solution {
public:
    int digitFrequencyScore(int n) {
        vector<int> freq(10, 0) ; 
        while( n ) {
            freq[n%10]++ ; 
            n /= 10 ; 
        }

        int ans = 0 ; 
        for( int d = 0 ; d < 10 ; d++ ) {
            ans += d * freq[d] ; 
        }

        return ans ; 
    }
};