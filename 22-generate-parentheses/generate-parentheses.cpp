class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0) {
            return {""};
        }
        vector<string> result;
        for (int c = 0; c < n; ++c) {
            for (string left : generateParenthesis(c)) {
                for (string right : generateParenthesis(n - 1 - c)) {
                    result.push_back("(" + left + ")" + right);
                }
            }
        }
        return result;
    }
};