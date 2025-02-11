class Solution {
private:
    void solve(vector<int> &nums, int idx, int n, vector<vector<int>> &ans ) {
        if( idx == n ) {
            ans.push_back(nums ) ;
            return ;
        }

        for( int i = idx ; i < n ; i++ ) {
            swap(nums[i], nums[idx] ) ;
            solve(nums, idx+1, n, ans ) ;
            swap(nums[i], nums[idx] ) ;
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size() ;
        vector<vector<int>> ans ;
        solve(nums, 0, n, ans ) ;
        return ans ;
    }
};