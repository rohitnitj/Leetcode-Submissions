class Solution {
public:
    string countAndSay(int n) {
        string ans = "1" ; 

        for( int i = 2 ; i <= n ; i++ ) {
            int cnt = 1 ; 
            string temp = "" ; 

            for( int j = 1 ; j < ans.size() ; j++ ) {
                if( ans[j] == ans[j-1] ) cnt++ ; 
                else {
                    temp += to_string(cnt) + ans[j-1] ; 
                    cnt = 1 ; 
                }
            }

            temp += to_string(cnt) + ans[ans.size()-1] ; 
            ans = temp ; 
        }

        return ans ; 
    }
};