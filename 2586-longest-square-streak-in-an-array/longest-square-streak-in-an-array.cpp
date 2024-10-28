class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        
        unordered_map<int,int> mpp ;
        sort(nums.begin(), nums.end() ) ;

        for( auto num : nums ) {
            int root = (int)sqrt(num ) ;

            if( root * root == num && mpp.find(root) != mpp.end() ) {
                mpp[num] = mpp[root] + 1 ;
            }
            else {
                mpp[num] = 1 ;
            }
        }

        int ans = -1 ;
        for( auto it : mpp ) {
            ans = max( ans, it.second ) ;
        }

        return ans == 1 ? -1 : ans ;
    }
};