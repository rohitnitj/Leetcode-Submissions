class Solution {
private :
    void solve(int i, vector<int> &arr, int sum, int target, vector<int> temp, vector<vector<int>> &ans){
        if( i < 0 ) return ;

        if( sum == target ) {
            ans.push_back(temp) ;
            return ;
        }

        if( sum > target ) return ;
        
        solve(i-1, arr, sum, target, temp, ans ) ; 

        temp.push_back(arr[i]) ;
        solve(i, arr, sum + arr[i], target, temp, ans ) ;
        temp.pop_back() ;
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size() ;
        vector<vector<int>> ans ;
        solve(n-1, candidates, 0, target, {}, ans ) ;
        return ans ;
    }
};