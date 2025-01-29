class Solution {
public:
    string reverseWords(string s) {
        vector<string> arr ;
        int n = s.size() ;

        string temp = "" ;
        for(int i = 0 ; i < n; i++ ) {
            if( s[i] == ' ' ) {
                if( !temp.empty() ){
                    arr.push_back(temp ) ;
                    temp = "" ;
                }
            }
            else {
                temp  += s[i] ;
            }
        }
        if( !temp.empty() ) {
            arr.push_back(temp ) ;
        }

        reverse(arr.begin(), arr.end() ) ;

        string ans = "" ;
        for( string s : arr ) {
            ans += s ;
            ans += " " ;
        }
        ans.pop_back() ;
        return ans ;
    }
};