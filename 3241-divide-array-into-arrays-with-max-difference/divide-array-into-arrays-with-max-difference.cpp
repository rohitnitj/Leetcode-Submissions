class Solution {
public:
    bool isValid( vector<vector<int>> arr, int k ) {
        int n = arr.size() ;
        for( int i = 0 ; i < n ; i++ ) {
            if( arr[i][2] - arr[i][0] > k ) return false ;
        }
        return true ;
    }

    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size() ;
        sort(nums.begin(), nums.end() ) ;
        
        vector<vector<int>> ans(n/3);
        for( int i = 0 ; i < n/3 ; i++ ) {
            for( int j = 3*i ; j < 3*i + 3 ; j++ ) {
                ans[i].push_back(nums[j] ) ;
            }
        }

        if( isValid(ans, k )) return ans ;
        else return {} ;
    }
};