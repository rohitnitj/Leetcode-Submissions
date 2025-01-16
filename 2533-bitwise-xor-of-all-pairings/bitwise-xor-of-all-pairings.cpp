class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size() ;
        int n2 = nums2.size() ;

        bool n1_even = ( n1 % 2 == 0 ) ;
        bool n2_even = ( n2 % 2 == 0 ) ;

        if( n1_even && n2_even ) return 0 ;
        
        int exor1 = 0, exor2 = 0 ;
        if( !n1_even ) {
            for( auto num : nums2 ) {
                exor2 ^= num ;
            }
        }

        if( !n2_even ) {
            for( auto num : nums1 ) {
                exor1 ^= num ;
            }
        }

        return exor1 ^ exor2 ;
    }
};