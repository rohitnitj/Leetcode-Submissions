class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        set<int> ans, prev ;
        for( int a : arr ) {
            set<int> curr ;
            curr.insert(a ) ;
            for( int p : prev ) curr.insert( p | a ) ;
            prev = curr ;
            for( int c : curr ) ans.insert( c ) ;
        }
        return ans.size() ;
    }
};