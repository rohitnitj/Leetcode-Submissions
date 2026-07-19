class Solution {
public:
    int myAtoi(string s) {
        return helper(s, 0, 0, 1, 0);
    }
    
private:
    int helper(const string& s, int i, long long num, int sign, int state) {
        if (i >= s.size()) {
            return sign * num;
        }
        
        if (state == 0) {
            if (s[i] == ' ') {
                return helper(s, i + 1, num, sign, 0);
            }
            if (s[i] == '+' || s[i] == '-') {
                return helper(s, i + 1, num, s[i] == '-' ? -1 : 1, 1);
            }
            if (isdigit(s[i])) {
                return helper(s, i, num, sign, 1);
            }
            return 0;
        }
        
        if (isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
            if (sign == 1 && num > INT_MAX) {
                return INT_MAX;
            }
            if (sign == -1 && num > 2147483648LL) {
                return INT_MIN;
            }
            return helper(s, i + 1, num, sign, 1);
        }
        
        return sign * num;
    }
};