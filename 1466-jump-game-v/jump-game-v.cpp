class Solution {
    int dfs(int i, const vector<int>& arr, int d, vector<int>& memo) {
        if (memo[i] != -1) {
            return memo[i];
        }
        
        int n = arr.size();
        int max_jumps = 1; 
        
        for (int j = i + 1; j <= min(i + d, n - 1); ++j) {
            if (arr[j] >= arr[i]) {
                break; 
            }
            max_jumps = max(max_jumps, 1 + dfs(j, arr, d, memo));
        }
        
        for (int j = i - 1; j >= max(0, i - d); --j) {
            if (arr[j] >= arr[i]) {
                break; 
            }
            max_jumps = max(max_jumps, 1 + dfs(j, arr, d, memo));
        }
        
        return memo[i] = max_jumps;
    }
    
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> memo(n, -1);
        int result = 1;
        
        for (int i = 0; i < n; ++i) {
            result = max(result, dfs(i, arr, d, memo));
        }
        
        return result;
    }
};