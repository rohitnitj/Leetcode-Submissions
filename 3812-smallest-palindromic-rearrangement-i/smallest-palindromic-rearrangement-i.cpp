class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        
        string half;
        char odd = 0;
        for (int i = 0; i < 26; ++i) {
            if (freq[i] % 2 == 1) {
                if (odd == 0) {
                    odd = 'a' + i;
                }
            }
            half += string(freq[i] / 2, 'a' + i);
        }
        
        string ans;
        ans += half;
        if (odd != 0) {
            ans += odd;
        }
        reverse(half.begin(), half.end());
        ans += half;
        
        return ans;
    }
};