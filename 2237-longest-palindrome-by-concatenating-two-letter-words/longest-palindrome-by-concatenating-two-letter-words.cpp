class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mpp;
        for (string word : words) mpp[word]++;

        int cnt = 0;
        bool central = false;

        for (auto &it : mpp) {
            string s1 = it.first;
            string s2 = s1;
            reverse(s2.begin(), s2.end());

            if (s1 == s2) {
                cnt += (it.second / 2) * 4;
                if (it.second % 2 == 1) central = true;
            } 
            else if (s1 < s2 && mpp.count(s2)) {
                int pairs = min(it.second, mpp[s2]);
                cnt += 4 * pairs;
            }
        }

        if (central) cnt += 2; 
        return cnt;
    }
};
