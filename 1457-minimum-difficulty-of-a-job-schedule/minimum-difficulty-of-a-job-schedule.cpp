class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if (n < d) return -1; // Not enough jobs

        vector<vector<int>> dp(n, vector<int>(d + 1, 1e9));

        // Base case: 1 day - must take max of all jobs from 0 to i
        int maxJob = 0;
        for (int i = 0; i < n; ++i) {
            maxJob = max(maxJob, jobDifficulty[i]);
            dp[i][1] = maxJob;
        }

        // Fill dp[i][k]: first i+1 jobs in k days
        for (int k = 2; k <= d; ++k) {
            for (int i = k - 1; i < n; ++i) {
                int maxD = 0;
                for (int j = i; j >= k - 1; --j) {
                    maxD = max(maxD, jobDifficulty[j]);
                    dp[i][k] = min(dp[i][k], dp[j - 1][k - 1] + maxD);
                }
            }
        }

        return dp[n - 1][d];
    }
};
