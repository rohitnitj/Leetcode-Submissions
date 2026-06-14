class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n1 = arr1.size() ; 
        int n2 = arr2.size() ; 

        map<int, int> cnt ; 
        for( int a : arr1 ) cnt[a]++ ; 

        vector<int> ans ; 
        for( int a : arr2 ) {
            while( cnt[a] ) {
                ans.push_back( a ) ;
                cnt[a]-- ; 
            }
        }   

        set<int> st ; 
        for( int a : arr2 ) st.insert(a) ; 

        sort( arr1.begin(), arr1.end() ) ; 

        for( int a : arr1 ) {
            if( st.find( a ) == st.end() ) ans.push_back(a) ; 
        }

        return ans ; 
    }
};