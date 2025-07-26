class Solution {
private:
    vector<int> generateRow(vector<int> prev ) {
        int n = prev.size() ;
        vector<int> ans(n+1 ) ;
        ans[0] = ans[n] = 1 ;

        for( int i = 1 ; i < n ; i++ ) {
            ans[i] = prev[i] + prev[i-1] ;
        }

        return ans ;
    }
    
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans ;
        vector<int> temp = {1} ;
        ans.push_back(temp ) ;

        for( int i = 1 ; i < numRows ; i++ ) {
            temp = generateRow(temp ) ;
            ans.push_back(temp ) ;
        }

        return ans ;
    }
};