class Solution {
public:
    int countMaxOrSubsets(vector<int> &nums){
        int n = nums.size() ;
        int maxOrValue = 0 ;

        for( int num : nums ) maxOrValue |= num ;
        
        vector<vector<int>> memo(n, vector<int>(maxOrValue + 1, -1 )) ;
        return countSubsetsRecursive(nums, 0, 0, maxOrValue, memo ) ;
    }

private:
    int countSubsetsRecursive(vector<int>&nums, int index, int currrentOr, int taragetOr, vector<vector<int>> &memo ) {

        if( index == nums.size() ) return ( currrentOr == taragetOr ) ? 1 : 0 ;
        if( memo[index][currrentOr] != -1 ) return memo[index][currrentOr] ;

        int countWithout = countSubsetsRecursive(nums, index + 1, currrentOr, taragetOr, memo ) ;
        int countWith = countSubsetsRecursive(nums, index + 1, currrentOr | nums[index], taragetOr, memo ) ;
        return memo[index][currrentOr] = countWith + countWithout ;
    }
};