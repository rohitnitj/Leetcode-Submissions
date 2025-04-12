class Solution {
private:
    bool subsetSumToK(int n, int k, vector<int> &arr) {
        vector<bool> prev(k+1, 0 ) ;
        vector<bool> curr(k+1, 0 ) ;
        prev[0] = curr[0] = true ;

        if (arr[0] <= k) {
            prev[arr[0]] = true;
        }

        for( int ind = 1 ; ind < n ; ind++ ) {
            for( int target = 1 ; target <= k ; target++ ) {

                bool notTake = prev[target ] ;
                bool take = false ;
                if( arr[ind] <= target ) take = prev[target - arr[ind]] ;

                curr[target] = take | notTake ;
            }

            prev = curr ;
        }    

        return prev[k] ;
    }

public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size() ;
        int sum = 0 ;

        for( int i = 0 ; i < n ; i++ ) {
            sum += nums[i] ;
        }

        if( sum % 2 ) return false ;
        int target = sum / 2 ;

        return subsetSumToK(n, target, nums ) ;
    }
};