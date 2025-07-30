class Solution {
public:
    string minWindow(string s, string t) {

        int n = s.size();
        int m = t.size();
        if (n < m) return "";
        
        int l = 0, r = 0;
        int minlen = INT_MAX;
        int sIndex = -1;

        vector<int> hashT(256, 0);
        vector<int> hashS(256, 0);
        int required = 0;

        for (int i = 0; i < m; i++) {
            if (hashT[t[i]] == 0) required++;
            hashT[t[i]]++;
        }

        int formed = 0;

        while (r < n) {

            char c = s[r];
            hashS[c]++;

            if (hashT[c] > 0 && hashS[c] == hashT[c]) {
                formed++;
            }

            while (l <= r && formed == required) {
                c = s[l];

                if (r - l + 1 < minlen) {
                    minlen = r - l + 1;
                    sIndex = l;
                }

                hashS[c]--;

                if (hashT[c] > 0 && hashS[c] < hashT[c]) {
                    formed--;
                }

                l++;
            }

            r++;
        }

        return sIndex == -1 ? "" : s.substr(sIndex, minlen);
    }
};