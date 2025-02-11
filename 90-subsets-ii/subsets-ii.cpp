class Solution {
private:
    void subset(vector<int> &nums, int idx, int n, vector<int> &temp, vector<vector<int>> &ans ) {
        if( idx == n ) {
            ans.push_back(temp ) ;
            return ;
        }

        temp.push_back(nums[idx] ) ;
        subset(nums, idx+1, n, temp, ans ) ;

        int i = idx ;
        while( i < n && nums[i] == nums[idx] ) i++ ;
        temp.pop_back() ;
        subset(nums, i, n , temp, ans ) ;
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size() ;
        sort(nums.begin(), nums.end() ) ;
        vector<vector<int>> ans ;
        vector<int> temp ;
        
        subset(nums, 0, n, temp, ans ) ;
        return ans ;        
    }
};