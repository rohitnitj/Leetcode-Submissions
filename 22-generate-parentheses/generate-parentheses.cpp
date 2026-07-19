class Solution {
public:
    bool isValid(string& p) {
        int bal = 0;
        for (char c : p) {
            if (c == '(') bal++;
            else bal--;
            if (bal < 0) return false;
        }
        return bal == 0;
    }

    void generateAll(string current, int n, vector<string>& result) {
        if (current.length() == 2 * n) {
            if (isValid(current)) {
                result.push_back(current);
            }
            return;
        }
        generateAll(current + '(', n, result);
        generateAll(current + ')', n, result);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generateAll("", n, result);
        return result;
    }
};