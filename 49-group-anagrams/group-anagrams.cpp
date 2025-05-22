class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size() ;
        vector<vector<string>> ans ;
        vector<int> vis(n, -1) ;

        vector<string> arr ;
        for( int i = 0 ; i < n ; i++ ) {
            string s = strs[i] ;
            sort(s.begin(), s.end() ) ;
            arr.push_back(s) ;
        }

        for( int i = 0 ; i < n ; i++ ) {
            vector<string> temp ;
            string t1 = arr[i] ;

            for( int j = i ; j < n ; j++ ) {
                string t2 = arr[j] ;

                if( t1 == t2 && vis[j] != 1 ) {
                    temp.push_back(strs[j] ) ;
                    vis[j] = 1 ;
                } 
            }

            if( temp.size() ) ans.push_back(temp ) ;
        }

        return ans ;
    }
};