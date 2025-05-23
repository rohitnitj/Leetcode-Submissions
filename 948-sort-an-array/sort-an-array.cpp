class Solution {
private:
    void heapify(vector<int> &arr, int n, int i ) {
        
        int larget = i ;
        int l = 2*i + 1 ;
        int r = 2*i + 2 ;

        if( l < n && arr[l] > arr[larget] ) larget = l ;
        if( r < n && arr[r] > arr[larget] ) larget = r ;

        if( larget != i ) {
            swap( arr[i], arr[larget] ) ;
            heapify(arr, n , larget ) ;
        }
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size() ;

        for( int i = n/2 - 1 ; i >= 0 ; i-- ) {
            heapify(nums, n, i ) ;
        }

        for( int i = n-1 ; i > 0 ; i-- ) {
            swap(nums[0], nums[i] ) ;
            heapify(nums, i , 0 ) ;
        }

        return nums ;
    }
};