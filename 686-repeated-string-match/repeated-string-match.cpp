class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int q = (B.size() - 1) / A.size() + 1;

        string repeated = "";
        for (int i = 0; i < q; ++i) repeated += A;

        if (repeated.find(B) != string::npos) return q;

        repeated += A;
        if (repeated.find(B) != string::npos) return q + 1;

        return -1;
    }
};
