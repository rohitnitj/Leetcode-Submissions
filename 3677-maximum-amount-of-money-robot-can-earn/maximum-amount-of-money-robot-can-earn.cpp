class Solution {
public:
    int maximumAmount(vector<vector<int>>& A) {
        int n = A.size();
        int m = A[0].size();

        const int NEG_INF = -1e9;

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(3, NEG_INF)));

        if (A[0][0] >= 0) {
            dp[0][0][0] = A[0][0];
        } else {
            dp[0][0][0] = A[0][0];   
            dp[0][0][1] = 0;         
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k <= 2; k++) {

                    if (i == 0 && j == 0) continue;

                    int best = NEG_INF;

                    if (i > 0 && dp[i-1][j][k] != NEG_INF) {
                        best = max(best, dp[i-1][j][k] + A[i][j]);
                    }
                    if (j > 0 && dp[i][j-1][k] != NEG_INF) {
                        best = max(best, dp[i][j-1][k] + A[i][j]);
                    }

                    dp[i][j][k] = max(dp[i][j][k], best);

                    if (A[i][j] < 0 && k > 0) {
                        int best2 = NEG_INF;

                        if (i > 0 && dp[i-1][j][k-1] != NEG_INF) {
                            best2 = max(best2, dp[i-1][j][k-1]);
                        }
                        if (j > 0 && dp[i][j-1][k-1] != NEG_INF) {
                            best2 = max(best2, dp[i][j-1][k-1]);
                        }

                        dp[i][j][k] = max(dp[i][j][k], best2);
                    }
                }
            }
        }

        return max({dp[n-1][m-1][0], dp[n-1][m-1][1], dp[n-1][m-1][2]});
    }
};