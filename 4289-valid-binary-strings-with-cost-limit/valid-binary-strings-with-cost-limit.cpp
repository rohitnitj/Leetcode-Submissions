class Solution {
public:
    void solve( int idx, int cost, vector<string> &ans, string temp, int n, int k ) {
        if( idx == n ) {
            if( cost <= k ) ans.push_back( temp ) ; 
            return ; 
        }

        if( idx == 0 ) {
            solve( idx + 1, cost, ans, temp + '0', n, k ) ; 
            solve( idx + 1, cost + idx, ans, temp + '1', n, k ) ; 
        }
        else if( temp[idx-1] == '1' ) {
            solve(idx+1, cost, ans, temp + '0', n, k ) ; 
        }
        else {
            solve(idx+1, cost, ans, temp + '0', n, k ) ; 
            solve(idx+1, cost + idx, ans, temp + '1', n, k ) ; 
        }
    }

    vector<string> generateValidStrings(int n, int k) {
        vector<string> ans ; 
        solve( 0, 0, ans, "", n, k ) ; 
        return ans ; 
    }
};