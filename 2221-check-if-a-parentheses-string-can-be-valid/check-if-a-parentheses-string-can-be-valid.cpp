class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if (n & 1) return false;

        int open = 0, unlock = 0;

        for (int i = 0; i < n; i++) {
            if (locked[i] == '0') {
                unlock++;
            } else if (s[i] == '(') {
                open++;
            } else {
                if (open > 0) {
                    open--;
                } else if (unlock > 0) {
                    unlock--;
                } else {
                    return false;
                }
            }
        }

        if (open > unlock) return false;

        open = unlock = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (locked[i] == '0') {
                unlock++;
            } else if (s[i] == ')') {
                open++;
            } else {
                if (open > 0) {
                    open--;
                } else if (unlock > 0) {
                    unlock--;
                } else {
                    return false;
                }
            }
        }

        return open <= unlock;
    }
};
