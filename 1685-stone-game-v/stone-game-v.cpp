class Solution {
    int memo[501][501];
    vector<int> prefixSum;

    int solve(const vector<int>& stoneValue, int left, int right) {
        if (left == right) {
            return 0; 
        }
        if (memo[left][right] != -1) {
            return memo[left][right];
        }

        int maxScore = 0;
        
        for (int i = left; i < right; ++i) {
            int sumLeft = prefixSum[i + 1] - prefixSum[left];
            int sumRight = prefixSum[right + 1] - prefixSum[i + 1];

            if (sumLeft < sumRight) {
                maxScore = max(maxScore, sumLeft + solve(stoneValue, left, i));
            } else if (sumLeft > sumRight) {
                maxScore = max(maxScore, sumRight + solve(stoneValue, i + 1, right));
            } else {
                maxScore = max(maxScore, sumLeft + max(solve(stoneValue, left, i), solve(stoneValue, i + 1, right)));
            }
        }
        
        return memo[left][right] = maxScore;
    }

public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        
        memset(memo, -1, sizeof(memo));
        
        prefixSum.assign(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + stoneValue[i];
        }
        
        return solve(stoneValue, 0, n - 1);
    }
};