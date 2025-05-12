class Solution {
public:

    void solve(vector<string> &ans , int n , int o, int c , string curr ){
        // base case
        if(curr.size() == n*2){
            ans.push_back(curr);
            return ;
        }

        if(o < n ){
            solve(ans , n , o+1 , c , curr + '(' ) ;
        }
        if(c < o ){
            solve(ans , n , o , c + 1 , curr + ')' ) ;
        }

    }

    vector<string> generateParenthesis(int n) {
        
        vector<string> ans ;
        solve(ans,n,0,0,"");

        return ans ;
    }
};