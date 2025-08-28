class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size() ;

        unordered_map<int, vector<int>> mpp ;
        for( int i = 0 ; i < n ; i++ ) mpp[groupSizes[i]].push_back( i ) ;

        vector<vector<int>> ans ;
        for( auto &[sz, arr] : mpp ) {
            if( arr.size() <= sz ) ans.push_back(arr ) ;
            else {
                vector<int> T = arr ;            
                vector<int> temp ;
                for( int a : arr ) {
                    if( temp.size() == sz ) {
                        ans.push_back(temp ) ;
                        temp.clear() ;
                    }
                    temp.push_back(a ) ;
                }
                if( temp.size() ) ans.push_back( temp ) ;
            }
        }

        return ans ;
    }   
};
