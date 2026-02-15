class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        
        map<int, int> mpp ;
        for( int num : nums ) mpp[num]++ ;

        map<int, int> F ;
        for( auto &[f, n] : mpp ) F[n]++ ;

        for( int num : nums ) {
            if( F[ mpp[num]] == 1 ) return num ;
        }

        return -1 ;
    }
};