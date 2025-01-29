class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size() ;
        unordered_map<int,int> mpp ;
        for( int a : arr ) {
            mpp[a]++ ;
        }

        unordered_set<int> st ;
        for( auto it : mpp ) {
            if( st.find(it.second ) == st.end() ) {
                st.insert(it.second ) ;
            }
            else {
                return false ;
            }
        }

        return true ;
    }
};