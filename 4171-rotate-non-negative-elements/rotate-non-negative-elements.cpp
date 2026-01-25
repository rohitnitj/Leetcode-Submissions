void printArray( vector<int> &arr ) {
    for( int a : arr ) {
        cout << a << " " ;
    }
    cout << endl ;
}

class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        int n = nums.size() ;
        
        vector<int> arr ;
        for( int num : nums ) {
            if( num >= 0 ) arr.push_back(num) ;
        }

        int m = arr.size() ;
        if( m == 0 ) return nums ; 
        k %= m ;

        vector<int> brr(m) ;
        for( int i = 0 ; i < m ; i++ ) {
            int idx = i - k ;
            if( idx < 0 ) idx += m ; 
            brr[idx] = arr[i] ;
        }

        int i = 0, j = 0 ;
        while( i < m ) {
            while( nums[j] < 0 ) j++ ;
            nums[j++] = brr[i++] ;
        }

        return nums ; 
    }
};