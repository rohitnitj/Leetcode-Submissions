class Solution {
private:    
    void solve(vector<int> &nums, int n, int i, vector<vector<int>> &ans, vector<int> temp ) {
        if( i == n ) {
            ans.push_back(temp ) ;
            return ;
        }

        temp.push_back(nums[i] ) ;
        solve(nums, n, i+1, ans, temp ) ;
        temp.pop_back() ;
        
        solve(nums, n, i+1, ans, temp ) ;
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size() ;
        vector<vector<int>> ans ;
        vector<int> temp ;
        solve(nums, n, 0, ans, temp ) ;
        return ans ;
    }
};