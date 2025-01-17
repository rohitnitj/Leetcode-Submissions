class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size() ;
        vector<int> org(n, 0 ) ;

        for( int i = 0 ; i < n-1 ; i++ ) {
            org[i+1] = org[i] ^ derived[i] ;
        }
        if( derived[n-1] == org[n-1] ^ org[0] ) return true ;

        org[0] = 1 ;
        for( int i = 0 ; i < n-1; i++ ) {
            org[i+1] = org[i] ^ derived[i] ;
        }
        if( derived[n-1] == org[n-1] ^ org[0] ) return true ;

        return false ;
    }
};