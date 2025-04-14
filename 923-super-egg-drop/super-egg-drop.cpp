class Solution {
public:
    int eggDrop(int n, int k) {
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        for (int i = 1; i <= n; ++i) {
            dp[i][0] = 0;
            dp[i][1] = 1;
        }

        for (int j = 1; j <= k; ++j) {
            dp[1][j] = j;
        }

        for (int i = 2; i <= n; ++i) {
            for (int j = 2; j <= k; ++j) {
                int low = 1, high = j, res = INT_MAX;

                while (low <= high) {
                    int mid = (low + high) / 2;
                    int break_case = dp[i - 1][mid - 1];  // Egg breaks
                    int no_break_case = dp[i][j - mid];  // Egg doesn't break
                    int worst = 1 + max(break_case, no_break_case);

                    if (break_case > no_break_case) {
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }

                    res = min(res, worst);
                }

                dp[i][j] = res;
            }
        }

        return dp[n][k];
    }

    int superEggDrop(int k, int n) {
        return eggDrop(k, n);
    }
};
