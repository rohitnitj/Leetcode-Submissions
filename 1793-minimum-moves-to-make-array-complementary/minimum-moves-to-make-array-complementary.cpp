class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        
        vector<int> delta(2 * limit + 2, 0);
        
        for (int i = 0; i < n / 2; ++i) {
            int A = min(nums[i], nums[n - 1 - i]);
            int B = max(nums[i], nums[n - 1 - i]);
            
            delta[A + 1] -= 1;
            delta[A + B] -= 1;
            delta[A + B + 1] += 1;
            delta[B + limit + 1] += 1;
        }
        
        int current_moves = n; 
        int min_moves = n;
        
        for (int target = 2; target <= 2 * limit; ++target) {
            current_moves += delta[target];
            min_moves = min(min_moves, current_moves);
        }
        
        return min_moves;
    }
};