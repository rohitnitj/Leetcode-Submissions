class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size() ; 

        map<char, int> freq ; 
        int left = 0, ans = 0 ; 

        for( int right = 0 ; right < n ; right++ ) {
            freq[s[right]]++ ; 

            while( freq['a'] >= 1 && freq['b'] >= 1 && freq['c'] >= 1 ) {
                ans += ( n - right ) ; 
                freq[s[left]]-- ; 
                left++ ; 
            }
        }

        return ans ;
    }
};