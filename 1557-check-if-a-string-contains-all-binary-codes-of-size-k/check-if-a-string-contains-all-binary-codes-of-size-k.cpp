class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        if (n < k) return false;

        int need = 1 << k;          // total binary codes
        vector<bool> seen(need, false);

        int mask = 0;
        int allOnes = need - 1;

        for (int i = 0; i < n; i++) {
            mask = ((mask << 1) & allOnes) | (s[i] - '0');

            if (i >= k - 1) {
                if (!seen[mask]) {
                    seen[mask] = true;
                    need--;
                    if (need == 0) return true;
                }
            }
        }
        return false;
    }
};