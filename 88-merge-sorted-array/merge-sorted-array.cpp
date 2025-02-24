class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for( int i = 0 ; i < n ; i++ ) {
            nums1[i+m] = nums2[i] ;
        }

        m = m + n ;
        int gap = m / 2 + m % 2 ;

        while( gap > 0 ) {
            int l = 0 , r = l+gap ;

            while( r < m ) {
                if( nums1[l] > nums1[r] ) swap(nums1[l], nums1[r] ) ;
                l++ , r++ ;
            }

            if( gap == 1 ) break ;
            gap = gap / 2 + gap % 2 ;
        }
    }
};