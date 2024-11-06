class Solution {
private:

bool isSorted(vector<int> &nums) {
    for( int i = 0 ; i < nums.size()-1 ; i++ ) {
        if( nums[i] > nums[i+1] ) return false ;
    }
    return true ;
}

int countSetBits(int num ) {
    int cnt = 0 ;
    while( num ) {
        if( num & 1 ) cnt++ ;
        num >>= 1 ;
    }
    return cnt ;
}

public:
    bool canSortArray(vector<int>& nums) {

        int n = nums.size() ;
        if( isSorted(nums) ) return true ;

        vector<int> setBits(n, 0) ;
        for( int i = 0 ; i < n; i++ ) {
            setBits[i] = countSetBits(nums[i] ) ;
        }

        for( int i = 0 ; i < n-1; i++ ) {
            for( int j = 0 ; j < n-i-1 ; j++ ) {
                if( nums[j] > nums[j+1] && setBits[j] == setBits[j+1] ) {
                    swap( nums[j], nums[j+1] ) ;
                }
            }
        }

        return isSorted(nums) ;

    }
};