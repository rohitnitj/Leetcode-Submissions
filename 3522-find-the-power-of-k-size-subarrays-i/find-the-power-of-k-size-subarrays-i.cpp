// TC : O ( N * K ) 
// SC : O ( N - K ) 

class Solution{
private:
    int find_power(vector<int> &nums, int s, int e ) {
        for( int i = s+1 ; i <= e ; i++ ) {
            if( nums[i] != nums[i-1] + 1 ) return -1 ;
        }
        return nums[e] ;
    }

public:
    vector<int> resultsArray(vector<int> &nums, int k ) {
        int n = nums.size() ;
        vector<int> ans ;

        for( int i = 0 ; i < n ; i++ ) {
            if( i+k-1 < n ) {
                int power = find_power(nums, i, i+k-1 ) ;
                ans.push_back(power ) ;
            }
        }

        return ans ;
    }
};