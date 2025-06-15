class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        string a = s, b = s;

        // Maximize: replace first non-'9' digit with '9'
        char val1 = 0;
        for (char ch : s) {
            if (ch != '9') {
                val1 = ch;
                break;
            }
        }
        if (val1) {
            for (char &ch : a) {
                if (ch == val1) ch = '9';
            }
        }

        // Minimize
        char val2 = 0;
        if (s[0] != '1') {
            val2 = s[0];
            for (char &ch : b) {
                if (ch == val2) ch = '1';
            }
        } 
        else {
            for (int i = 1; i < s.size(); i++) {
                if (s[i] != '0' && s[i] != '1') {
                    val2 = s[i];
                    for (int j = 1; j < b.size(); j++) {
                        if (b[j] == val2) b[j] = '0';
                    }
                    break;
                }
            }
        }

        int a1 = stoi(a), b1 = stoi(b);
        return a1 - b1;
    }
};
