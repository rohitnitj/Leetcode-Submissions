class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n = s.length();
        int m = t.length();
        
        if (n > m) return false;

        vector<int> pref(n, -1);
        for (int i = 0, j = 0; i < n; ++i) {
            while (j < m && t[j] != s[i]) {
                j++;
            }
            if (j < m) {
                pref[i] = j++;
            } else {
                break;
            }
        }

        if (pref[n - 1] != -1) return true;

        vector<int> suff(n, -1);
        for (int i = n - 1, j = m - 1; i >= 0; --i) {
            while (j >= 0 && t[j] != s[i]) {
                j--;
            }
            if (j >= 0) {
                suff[i] = j--;
            } else {
                break;
            }
        }

        for (int i = 0; i < n; ++i) {
            int L = (i == 0) ? -1 : pref[i - 1];
            int R = (i == n - 1) ? m : suff[i + 1];

            if (i > 0 && L == -1) continue;
            if (i < n - 1 && R == -1) continue;

            if (R - L >= 2) {
                return true;
            }
        }

        return false;
    }
};