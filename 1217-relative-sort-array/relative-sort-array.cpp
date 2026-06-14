class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n1 = arr1.size() ; 
        int n2 = arr2.size() ;

        map<int, int> freq ; 
        for( int a : arr1 ) freq[a]++ ; 

        vector<int> ans ; 
        
        for( int a : arr2 ) {
            while( freq[a]){
                ans.push_back( a ) ; 
                freq[a]-- ; 
            }
        }

        int idx = ans.size() ; 

        set<int> st ; 
        for( int a : arr2 ) st.insert(a) ; 

        for( int a : arr1 ) {
            if( st.find(a) == st.end() ) ans.push_back(a) ; 
        }

        sort( ans.begin() + idx, ans.end() ) ; 

        return ans ; 
    }
};