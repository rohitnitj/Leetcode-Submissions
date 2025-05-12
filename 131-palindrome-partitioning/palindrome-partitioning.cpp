class Solution {
private:
    bool isPalindrome(int i, int j, const string &s) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    void solve(int start, const string &s, vector<string> &temp, vector<vector<string>> &ans) {
        if (start == s.size()) {
            ans.push_back(temp);
            return;
        }

        for (int end = start; end < s.size(); end++) {
            if (isPalindrome(start, end, s)) {
                temp.push_back(s.substr(start, end - start + 1));
                solve(end + 1, s, temp, ans);
                temp.pop_back();  // backtrack
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(0, s, temp, ans);
        return ans;
    }
};
