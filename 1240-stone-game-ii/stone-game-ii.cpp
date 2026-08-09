class Solution {
private:
    int helper(vector<int> &piles, vector<vector<int>> &dp, vector<int> &sums, int i, int m, int n) {
        if (i == n) return 0;
        if (2 * m >= n - i) return sums[i];
        if (dp[i][m]) return dp[i][m];

        int mini = 1e9;
        for (int j = 1; j <= 2 * m; j++) {
            mini = min(mini, helper(piles, dp, sums, i + j, max(j, m), n));
        }

        return dp[i][m] = sums[i] - mini;
    }

public:
    int stoneGameII(vector<int>& piles) {
        if (piles.empty()) return 0;

        int n = piles.size();
        vector<int> sums(n, 0);
        
        // Calculate the prefix sums in reverse
        sums[n-1] = piles[n-1];
        for (int i = n - 2; i >= 0; i--) {
            sums[i] = piles[i] + sums[i + 1];
        }

        vector<vector<int>> dp(n, vector<int>(n, 0));
        return helper(piles, dp, sums, 0, 1, n);
    }
};
