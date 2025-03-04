class Solution {
private:
    bool func(int idx, int sum, int n, unordered_map<string, bool>& dp) {
        string key = to_string(idx) + "," + to_string(sum);
        if (dp.find(key) != dp.end()) return dp[key];
        if (sum == n) return dp[key] = true;
        if (pow(3, idx) > n) return dp[key] = false;
        return dp[key] = func(idx + 1, sum + pow(3, idx), n, dp) || func(idx + 1, sum, n, dp);
    }

public:
    bool checkPowersOfThree(int n) {
        unordered_map<string, bool> dp;
        return func(0, 0, n, dp);
    }
};