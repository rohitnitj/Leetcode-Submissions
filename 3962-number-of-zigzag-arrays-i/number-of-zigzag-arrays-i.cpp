class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        int MOD = 1e9 + 7;
        
        vector<int> dp0(m + 2, 0);
        vector<int> dp1(m + 2, 0);
        vector<int> next_dp0(m + 2, 0);
        vector<int> next_dp1(m + 2, 0);
        
        for (int i = 1; i <= m; ++i) {
            dp0[i] = 1;
            dp1[i] = 1;
        }

        for (int len = 2; len <= n; ++len) {
            long long pref1 = 0;
            for (int y = 1; y <= m; ++y) {
                next_dp0[y] = pref1;
                pref1 = (pref1 + dp1[y]) % MOD;
            }
            
            long long suff0 = 0;
            for (int y = m; y >= 1; --y) {
                next_dp1[y] = suff0;
                suff0 = (suff0 + dp0[y]) % MOD;
            }

            swap(dp0, next_dp0);
            swap(dp1, next_dp1);
        }

        long long ans = 0;
        for (int i = 1; i <= m; ++i) {
            ans = (ans + dp0[i]) % MOD;
            ans = (ans + dp1[i]) % MOD;
        }

        return ans;
    }
};