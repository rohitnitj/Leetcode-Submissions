class Solution {
private:
    int digitSum(int n ){
        int sum = 0 ;
        while( n ) {
            sum += n % 10 ;
            n /= 10 ;
        }
        return sum ;
    }

public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size() ;

        map<int, vector<int> > mpp ;

        for( auto num : nums ) {
            int dsum = digitSum(num ) ;
            mpp[dsum].push_back(num ) ;
        }

        int ans = -1 ;
        for( auto &it : mpp ) {
            vector<int> arr = it.second ;

            if( arr.size() >= 2 ) {
                sort(arr.begin(), arr.end() ) ;
                ans = max( ans, arr[arr.size()-1] + arr[arr.size() - 2 ] ) ;
            }
        }

        return ans ;
    }
};