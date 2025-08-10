class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s = sortedDigits(n);
        static unordered_set<string> powers = precompute();
        return powers.count(s) > 0;
    }

private:
    string sortedDigits(int x) {
        string s = to_string(x);
        sort(s.begin(), s.end());
        return s;
    }
    
    static unordered_set<string> precompute() {
        unordered_set<string> st;
        for (int i = 1; i <= 1e9; i <<= 1) {
            string s = to_string(i);
            sort(s.begin(), s.end());
            st.insert(s);
        }
        return st;
    }
};
