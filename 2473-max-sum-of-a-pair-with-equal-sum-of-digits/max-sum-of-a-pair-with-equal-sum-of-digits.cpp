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

        vector<pair<int,int>> mpp ;

        for( auto num : nums ) {
            int dsum = digitSum(num ) ;
            mpp.push_back( {dsum, num } ) ;
        }

        sort( mpp.begin(), mpp.end() ) ;

        int ans = -1 ;

        for( int i = 1 ; i < mpp.size() ; i++ ) {
            
            if( mpp[i].first == mpp[i-1].first ) {
                ans = max( ans, mpp[i].second + mpp[i-1].second ) ;
            }
        }

        return ans ;
    }
};