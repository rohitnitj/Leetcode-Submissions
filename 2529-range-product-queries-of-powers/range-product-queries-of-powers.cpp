class Solution {
public:
    static const long long MOD = 1e9 + 7;

    long long modPow(long long base, long long exp) {
        long long res = 1;
        while (exp > 0) {
            if (exp & 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return res;
    }

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;
        for (int i = 0; i < 31; i++) {
            if (n & (1 << i)) {
                powers.push_back(1 << i);
            }
        }
        
        int m = powers.size();
        vector<long long> prefix(m + 1, 1);
        for (int i = 0; i < m; i++) {
            prefix[i + 1] = (prefix[i] * powers[i]) % MOD;
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto &q : queries) {
            int l = q[0], r = q[1];
            long long numerator = prefix[r + 1];
            long long denominator = prefix[l];

            long long inv = modPow(denominator, MOD - 2);
            ans.push_back((numerator * inv) % MOD);
        }

        return ans;
    }
};