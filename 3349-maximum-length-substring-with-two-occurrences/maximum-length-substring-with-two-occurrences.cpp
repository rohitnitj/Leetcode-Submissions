class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size() ; 

        map<char, int> freq ; 
        int left = 0, right = 0 ;
        int ans = 0 ; 

        for( right = 0 ; right < n ; right++ ) {
            freq[s[right]]++ ; 

            while( freq[s[right]] > 2 ) {
                freq[s[left]]-- ; 
                left++ ; 
            }

            ans = max(ans, right - left + 1 ) ; 
        }

        return ans ; 
    }
};